// GPS using gpsd
//
// Author: Matthew Knight
// File Name: daemon-gps.hpp
// Date: 2019-04-10

#include "gps.hpp"

#include "bridge.hpp"

namespace Sailbot {
	/**
	 * Gpsd client wrapper
	 *
	 * This class implements the Gps interface and uses gpsd to parse data
	 * coming in via uart.
	 */
	class DaemonGps : public Gps {
		Bridge::WriteAccess<SystemCoordinates> coordinates;
		gpsmm gpsRx;
		std::atomic<bool> running = true;

	public:
		DaemonGps(Bridge& bridge);

		~DaemonGps();
	};
}
