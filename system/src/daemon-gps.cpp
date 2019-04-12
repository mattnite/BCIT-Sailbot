// GPS using gpsd
//
// Author: Matthew Knight
// File Name: daemon-gps.cpp
// Date: 2019-04-10

#include "daemon-gps.hpp"

#include <libgpsmm.h>

#include <iostream>
#include <atomic>
#include <chrono>
#include <thread>

namespace Sailbot {
	DaemonGps::DaemonGps(Bridge& bridge)
		: bridge(bridge)
		, gpsRx("localhost", "2947") 
		, thread([&]() {
			while (running) {
				struct gps_data_t *newData;

				if (!gpsRx.waiting(5000000))
					continue;

				if ((newData = gpsRx.read()) == NULL) {
					std::cerr << "GPS: Read Error" << std::endl;
				}
				else if (newData->status && (LATLON_SET & newData->set)) {
					Coordinates coord {
						newData->fix.latitude,
						newData->fix.longitude
					};

					bridge.setCoordinates(coord);
				}
			}
		})
	
	{
		if (gpsRx.stream(WATCH_ENABLE|WATCH_JSON) == NULL)
			throw std::runtime_error("gpsd not running"); 
	}

	DaemonGps::~DaemonGps() {
		running = false;
		thread.join();
	}
}
