// Author: Matthew Knight
// File Name: imu.cpp
// Date: 2017-06-27

// This Thread periodically reads the IMU and updates values accordingly

#include <iostream>
#include <chrono>
#include <thread>
#include "sbThreads.hpp"

void imu(varTable *systemVar)
{
    std::cout << "IMU: Initializing..." << std::endl;
    
    try
    {
	// Test to see if IMU is there
    }
    catch (...)
    {
	// If exception thrown then notify main thread
	std::cout 
	    << "IMU: Error: Could not access IMU Module" << std::endl
	    << "IMU: Shuting Down..." << std::endl;
	return;
    }
    
    // Set up timing
    std::chrono::duration<int, std::milli> interval(2000), timer;
    std::chrono::system_clock::time_point current;
     
    // Print system message
    std::cout << "IMU: Initialized!" << std::endl;

    while (true)
    {
	current = std::chrono::system_clock::now();
	
	// Do things
	std::cout << "IMU: Poll" << std::endl;	
	
	if (current + interval > std::chrono::system_clock::now())
	    std::this_thread::sleep_until(current+interval);
    }
}
