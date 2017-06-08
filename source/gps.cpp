// GPS Thread

// Author: Matthew Knight
// FileName: gps.cpp
// Date: 2017-06-02

// This is the gps thread for the sailbot. It periodically updates the gps
// coordinates in the system variables table.

#include <iostream>
#include <atomic>
#include <thread>
#include <chrono>
#include <ctime>
#include "varTable.hpp"

void gps(varTable *systemVar);

// Sampling thread
void gps(varTable *systemVar)
{
    std::cout << "GPS: Initializing..." << std::endl;

    // Set up serial port
    

    // Configure GPS
    
    // Set up timing
    std::chrono::duration<int, std::milli> interval(2000), timer;
    std::chrono::system_clock::time_point current;
     
    // Print system message
    std::cout << "GPS: Initialized!" << std::endl;

    while (true)
    {
	current = std::chrono::system_clock::now();
	
	// Do things
	std::cout << "GPS: Lat: " << systemVar->lat.load() <<std::endl;
	
	
	if (current + interval > std::chrono::system_clock::now())
	    std::this_thread::sleep_until(current+interval);
    }
}
