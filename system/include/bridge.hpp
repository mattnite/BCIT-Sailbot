// The Bridge
//
// Author: Matthew Knight
// File Name: bridge.hpp
// Date: 2019-03-23

#pragma once

#include "gps.hpp"
#include "imu.hpp"
#include "types.hpp"
#include "wind.hpp"

namespace Sailbot {

	/**
	 * @brief Bridge
	 *
	 * This class contains all the modules pertaining to running the sailbot.
	 * All other modules communicate with the Bridge as it controls the flow of
	 * information and determines the heading and/or mode of the sailbot.
	 */
	class Bridge {
		SystemCoordinates coordinates;
		SystemKinetics kinetics;
		SystemWind reading;

		GpsPtr gps;
		ImuPtr imu;
		WindPtr wind;

	public:
		Bridge(const Configuration& config);
		
		void setCoordinates(const Gps::Coordinates& coord);
		void setImuData(const Imu::Data& kinetics);
		void setWindReading(const Wind::Reading& reading);

		Gps::Coordinates getCoordinates();
		Imu::Data getImuData();
		Wind::Reading getWindReading();
	};
}
