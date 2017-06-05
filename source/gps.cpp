// GPS Server

// Author: Matthew Knight
// FileName: gps.cpp
// Date: 2017-06-02

// This program is the gps server for the sailbot. If a program requests the gps
// coordinates it will reply with the last sampled position.

#include <iostream>
#include <atomic>
#include <thread>
#include <chrono>
#include "zmq.hpp"

// Sampling thread
void gps(void)
{
    std::chrono::duration interval(milliseconds(100));
    while (true)
    {
	std::chrono::time_point current = std::chrono::system_clock::now();
	
	// Do things

	if (current + interval > std::chrono::system_clock::now();)
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
