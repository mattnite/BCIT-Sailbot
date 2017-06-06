// BCIT Sailbot Control System Main Thread

// Author: Matthew Knight
// File Name: main.cpp
// Date: 2017-06-05

// This is the main thread for the sailbot's control system.

#include <iostream>
#include <thread>
#include <functional>
#include "varTable.hpp"
#include "gps.hpp"

// Main thread (server thread)
int main(void)
{
    // Initialize system variables
    varTable system;
    system.lat = 1.0;
    // create gps sampling thread
    std::thread gpsThread(gps, &system);
    std::cout << "Made GPS Thread" << std::endl;
    
    gpsThread.detach();
    // run forever
    while (true)
	;
}
