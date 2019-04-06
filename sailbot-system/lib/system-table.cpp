// System Table Interface
//
// Author: Matthew Knight
// File Name: system-table.cpp
// Date: 2018-10-10
//
// This class manages the semaphores and shared memory where the system table is
// located.

#include "system-table.hpp"
#include "table.hpp"
#include "sem-lock.hpp"

#include <errno.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/stat.h>

#include <fstream>
#include <iostream>

#define SEM_NUM 2
#define SHM_AVAILABLE 0
#define INSTANCES 1

union semun {
	int val;
	struct semid_ds *buf;
	unsigned short *array;
	struct seminfo *__buf;
};

// The table can be found using a pathname
SystemTable::SystemTable(const char *pathname) : p(pathname){
	int fileSize;
	key_t key;
	struct shmid_ds shm;
	
	// create file if it doesn't exit
	std::ofstream create(p, std::ios::app);
	create.close();

	// open file and check length
	std::ifstream file(p);
	file.seekg(0, std::ios::end);
	fileSize = file.tellg();
	file.seekg(0, std::ios::beg);
	
	// Now create semaphores
	union semun arg;
	struct semid_ds buf;
	key = ftok(pathname, 'S');
	semid = semget(key, 2, 0666 | IPC_CREAT | IPC_EXCL);
	
	if (semid == -1 && errno == EEXIST) {
		// wait for initialization
		semid = semget(key, 2, 0666);
		if (semid == -1)
			throw errno;

		arg.buf = &buf;
		do {
			if (semctl(semid, 0, IPC_STAT, arg))
				throw errno;
		} while (arg.buf->sem_ctime == 0);
		
		// increment client count
		struct sembuf ops = { INSTANCES, 1, SEM_UNDO };
		if (semop(semid, &ops, 1))
			throw errno;

	} else {
		// initialize the semaphores
		ushort array[SEM_NUM] = { 1, 0 };
		arg.array = array;
		if (semctl(semid, 0, SETALL, arg))
			throw errno;
	}
	
	// lock the semaphore
	SemLock lck(semid, SHM_AVAILABLE);

	// Getting the shared memory segment	
	key = ftok(pathname, 'R');
	shmid = shmget(key, sizeof(Table),0666);
	if (shmid == -1 && errno == ENOENT) {
		// create shared memory
		shmid = shmget(key, sizeof(Table), 0666 | IPC_CREAT);
		if (shmid == -1)
			throw errno;
	} else if (shmid == -1) {
		throw errno;
	}
	
	// get number of attached 
	if (shmctl(shmid, IPC_STAT, &shm))
		throw errno;

	// get pointer to memory
	void *data = shmat(shmid, (void*)0, 0);
	if (data == (char*)(-1))
		throw "issue attaching";
	
	if (shm.shm_nattch > 0) {
		// already attached processes, continue as normal
		t = (Table*)data;
	} else if (fileSize == sizeof(Table)) { 
		// initialize with saved data
		file.read((char*)data, sizeof(Table));
		t = (Table*)data;
	} else {
		// initialize using default
		t = new (data) Table;
	}
}

// Get copy of the table
Table SystemTable::getTable() {
	// lock down semaphore
	SemLock lck(semid, SHM_AVAILABLE);
	// copy table
	Table table = *t;
	return table;
}

// Set coordinates in table
void SystemTable::setCoords(double lat, double lon) {
	// lock down semaphore
	SemLock lck(semid, SHM_AVAILABLE);	
	t->coords = std::complex<double>(lat, lon);
}

// dtor destructs table if it's no longer there.
SystemTable::~SystemTable() {
	std::ofstream file(p);
	file.write((char*)t, sizeof(Table));
	// detach
	if (shmdt(t))
		std::cerr << "Failed detaching from shared memory" << std::endl;

	struct sembuf dec = { INSTANCES, -1, IPC_NOWAIT | SEM_UNDO };

	// Check if we need to clean up
	if (semop(semid, &dec, 1)) {
		// destroy memory
		if(shmctl(shmid, IPC_RMID, nullptr))
			std::cerr << "Could not desroy shared memory" << std::endl;
		// destroy semaphores
		if (semctl(semid, 0, IPC_RMID))
			std::cerr << "Could not destroy semaphores" << std::endl;
	}
}
