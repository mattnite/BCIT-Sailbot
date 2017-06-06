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

// Sampling thread
void gps(void)
{
    std::chrono::duration<int, std::milli> interval;
    std::chrono::system_clock::time_point current;
    
    while (true)
    {
	current = std::chrono::system_clock::now();
	
	// Do things
	std::cout << "Reading GPS at " << std::endl;

	if (current + interval > std::chrono::system_clock::now())
	    std::this_thread::sleep_until(current+interval);
    }
}

// Main thread (server thread)
int main(void)
{
    // create sampling thread

    std::thread (gps, NULL).detach();

    // run forever
    while (true)
	;
}
