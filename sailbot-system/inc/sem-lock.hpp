// Semaphore lock class
//
// Author: Matthew Knight
// File Name: sem-lock.hpp
// Date:2018-10-14
//
// This class's lifetime locks down a sysV semaphore that is already in
// existence. It does implement RAII to aquire the semaphore, but the semaphore
// does need to be initialized before this object can be created, otherwise it
// will emit an exception.

// TODO: There is the possibility that a process could terminate without
// releasing the semaphore, locking the resource indefinitely. I need to figure
// out how to remedy this.

#ifndef SEMAPHORE_LOCK_HPP
#define SEMAPHORE_LOCK_HPP

#include <cerrno>
#include <iostream>
#include <system_error>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

class SemLock {
	int id;
	short op;
	unsigned short num;

public:
	// ctor -- sem_op determines the decrement value
	SemLock(int semid, unsigned short sem_num, short sem_op=-1) 
		: id(semid), num(sem_num), op(sem_op) 
	{
		struct sembuf buf = { num, op, SEM_UNDO };
		if (semop(id, &buf, 1))
			std::system_error(errno, std::generic_category());

	}
	
	// dtor -- release semaphore
	~SemLock() {
		short reverse = -1*op;
		struct sembuf buf = { num, reverse, SEM_UNDO };
		if (semop(id, &buf, 1)) {
			std::cerr 
				<< "Error releasing sysV semaphore: " 
				<< errno 
				<< std::endl;
		}
	}
};

#endif // SEMAPHORE_LOCK_HPP
