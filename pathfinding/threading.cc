// Threading test program

// Author: Matthew Knight
// Date: 2016-11-23

// This program is a starting point for learning code dealing with
// multithreading.

#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <atomic>
#include "node.h"


// Main thread, schedules all the rest
int main(void)
{
    // Initialize System Constants
    unsigned int sysTick = 10000;	// Length of system tick in usec

    // Initialize system variables
    atomic_int heading = 0;		// Compass Angle adjusted for position
					// North is 0, incrementing clockwise
					// degrees
    atomic_int heelAngle;		// Angle of heel in degrees
    atomic_int velocity;			// Magnitude of velocity in mm/sec
    atomic_int longitude;		// GPS Coordinates * 10^6
    atomic_int latitude;			
    atomic_int windSp;			// Wind speed
    atomic_int windDir;			// Wind direction
    
    Node* buoys = NULL;			// Linked List of Buoy Nodes
    Node* obstacles = NULL;		// Linked List of Obstacle Nodes

    // Initialize scheduled task list
    sch = taskList(sysTick);
    sch.addTask(&input, inPer);		// Input from wind and IMU
    sch.addTask(&gps, gpsPer);		// gps polling
    sch.addTask(&findPath, pathPer);	// Re-evaluate pathfind
    sch.addTask(&manAuto, manPer);	// check if in manual or auto mode
    sch.addTask(&cam, camPer);		// detect buoys
    sch.addTask(&lidar, lidPer);	// detect obstacles

    // Run tasks
    scheduler.run();


}

// Polls and stores values from IMU and wind sensors
void input()
{
    
}

// Poll gps
void gps()
{

}

// Determine path to waypoint
void findPath()
{

}

// Determine if in manual or auto mode
void manAuto()
{
    
}

// Sail aileron position control loop
void aileron()
{

}

// Rudder aileron position control loop
void rudder()
{

}

// Detect buoys
void cam()
{

}

// Detect objects
void lidar()
{

}
