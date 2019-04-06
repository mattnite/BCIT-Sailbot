// Wind Polling thread

// Author: Matthew Knight
// File Name: wind.cpp
// Date: 2017-06-27

// This Thread periodically reads the interface to the wind sensor and updates
// the values in the variable table accordingly.

#include <iostream>
#include <chrono>
#include <thread>
#include "sbThreads.hpp"

void wind(varTable *systemVar)
{
    std::cout << "WIND: Initializing..." << std::endl;
    
    try
    {
	// Test to see if Wind Communication is there
    }
    catch (...)
    {
	// If exception thrown then notify main thread
	std::cout 
	    << "WIND: Error: Could not access Wind Sensor" << std::endl
	    << "WIND: Shuting Down..." << std::endl;
	return;
    }
    
    // Set up timing
    std::chrono::duration<int, std::milli> interval(2000), timer;
    std::chrono::system_clock::time_point current;
     
    // Print system message
    std::cout << "WIND: Initialized!" << std::endl;

    while (true)
    {
	current = std::chrono::system_clock::now();
	
	// Do things
	std::cout << "WIND: Poll" << std::endl;	
	
	if (current + interval > std::chrono::system_clock::now())
	    std::this_thread::sleep_until(current+interval);
    }
}
