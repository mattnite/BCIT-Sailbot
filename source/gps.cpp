// GPS Thread

// Author: Matthew Knight
// FileName: gps.cpp
// Date: 2017-06-02

// This is the gps thread for the sailbot. It periodically updates the gps
// coordinates in the system variables table.

#ifndef GPS_THREAD
#define GPS_THREAD

#include <iostream>
#include <atomic>
#include <chrono>
#include <thread>
#include <libgpsmm.h>
#include "varTable.hpp"
#include "sbThreads.hpp"

// GPS interface thread
void gps(varTable *systemVar)
{
    std::cout << "GPS: Initializing..." << std::endl;

    // Initialize connection to GPS Daemon
    gpsmm gpsRec("localhost", "5555");
    
    if (!gpsRec.is_open())
    {
	std::cout << "GPS: Error constructor failed" << std::endl;
	return;
    }

    if (gpsRec.stream(WATCH_ENABLE|WATCH_JSON) == NULL)
    {
	std::cout << "GPS: gpsd is not running!" << std::endl;
	return;
    }

    // Print system message
    std::cout << "GPS: Initialized!" << std::endl;

    while (true)
    {
	struct gps_data_t *newData;

	if (!gpsRec.waiting(5000000))
	    continue;

	if ((newData = gpsRec.read()) == NULL)
	    std::cout << "GPS: Read Error" << std::endl;
	else
	{
	    if (newData->status)
	    {
		if (LATLON_SET & newData->set)
		    std::cout << "GPS: New coordinates" << std::endl;
	    
	    }
	}
    }
}

#endif
