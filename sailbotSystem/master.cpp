// master process

// Author: Matthew Knight
// File Name: master.cpp
// Date: 2017-08-03

// This process first sets up IPC, starts other processes and then does the
// decision making and data routing during operation.

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include <sys/sem.h>
#include "sailbotTypes.h"

#include "json.hpp"

// Need file locks for:
//  - objects
//  - Commands
//  - path

enum semaphore
{
    server,
    gps,
    imu,
    wind,
    lin,
    num_semaphores
}

int main(void)
{

    key_t key;

    // IPC with server frontend
/*
    // Memory mapped file for objects
    int fd, pagesize;
    char *mapped;

    fd = open("/home/mknight/objects", O_RDONLY);
    pagesize = getpagesize();
    mapped = (char*)mmap((caddr_t)0, pagesize, PROT_READ, MAP_SHARED, fd, pagesize);

    // Memory mapped file for commands
    int fd, pagesize;
    char *mapped;

    fd = open("/home/mknight/commands", O_RDONLY);
    pagesize = getpagesize();
    mapped = (char*)mmap((caddr_t)0, pagesize, PROT_READ, MAP_SHARED, fd, pagesize);
 */   
    // Shared memory with server
    int shmid;
    char *data;
    struct _serverData
    {
	int mode;
	int cflag;
	double rudder;
	double aileron;
    } serverData;

    key = ftok(".server", 'S');
    shmid = shmget(key, sizeof(serverData), 0644 | IPC_CREAT);
    data = (char*)shmat(shmid, (void*)0, 0);

    // Shared memory with GPS
    struct _gpsData
    {
	double lon;
	double lat;
	double lon_err;
	double lat_err;
    } gpsData;
    
    key = ftok(".gps", 'S');
    
    // Shared memory with IMU
    struct _imuData
    {
	double heading;
	double linAcc[3];
	double quat[3];
    } imuData;

    key = ftok(".imu", 'S');
    
    // Shared memory with Wind
    struct _windData
    {
	double speed;
	double direction;
    } windData;

    key = ftok(".wind", 'S');
    
    // Shared memory with linear actuator control
    struct _linActData
    {
	double rudder;
	double ailerone;
    } linActData;
    
    key = ftok(".lin", 'S');

    // Semaphore set
    key = ftok(".sem", 'S');
    int semid = semget(key, num_semaphores, 0666 | IPC_CREAT);
    
    std::cout << "Initialization complete, starting processes..." << std::endl;
    
    // Now start all the processes
    system("server");
    system("gps");
    system("imu");
    system("wind");
    system("linAct");

}
