// BCIT Sailbot Control System Main Thread

// Author: Matthew Knight
// File Name: main.cpp
// Date: 2017-06-05

// This is the main thread for the sailbot's control system.

#include <iostream>
#include <thread>
#include <functional>
#include <atomic>
#include "varTable.hpp"
#include <unistd.h>
// Thread source files
#include "gps.cpp"

// Main thread (server thread)
int main(void)
{
    double val = 0.0;

    // Initialize system variables
    varTable system;
    system.lat.store(val);
    // create gps sampling thread
    std::thread gpsThread(gps, &system);
     
    gpsThread.detach();
    
    // run forever
    while (true)
    {
	sleep(3);
	system.lat.store(++val);
    }
}
