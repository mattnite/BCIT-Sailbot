// GPS Thread

// Author: Matthew Knight
// FileName: gps.cpp
// Date: 2017-06-02

// This is the gps process for the sailbot, it simply waits for fixes and send
// the appropriate data (gps coordinates and errors) to the master process.

#include <thread>
#include <libgpsmm.h>
#include "json.hpp"

// GPS server Process
void main(void)
{
    std::cout << "GPS: Initializing..." << std::endl;

    // Initialize shared memory segment


    // Initialize connection to GPS Daemon
    gpsmm gpsRec("localhost", "2947");
    
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
		{
		    // Send data to shared memory
		}
	    }
	}
    }
}
