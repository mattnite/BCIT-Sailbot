// GPS using gpsd
//
// Author: Matthew Knight
// File Name: daemon-gps.hpp
// Date: 2019-04-10

#pragma once

#include "gps.hpp"

#include "bridge.hpp"
#include "types.hpp"
#include "write-access.hpp"

#include <libgpsmm.h>

#include <atomic>
#include <thread>

namespace Sailbot {
	/**
	 * Gpsd client wrapper
	 *
	 * This class implements the Gps interface and uses gpsd to parse data
	 * coming in via uart.
	 */
	class DaemonGps : public Gps {
		Bridge& bridge;
		gpsmm gpsRx;
		bool running;
		std::thread thread;

	public:
		DaemonGps(Bridge& bridge);

		~DaemonGps();
	};
}
