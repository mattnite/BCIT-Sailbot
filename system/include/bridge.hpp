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
#include "write-access.hpp"

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
//		SystemKinetics kinetics;
//		SystemWind wind;

		GpsPtr gps;
//		ImuPtr imu;
//		WindPtr wind;

	public:
		void setCoordinates(const Gps::Coordinates& coord);

		Gps::Coordinates getCoordinates();

//		Bridge(const Configuration& config);
	};
}
