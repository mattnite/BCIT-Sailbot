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
		SystemWind wind;

		GpsPtr gps;
		ImuPtr imu;
		WindPtr wind;
		
	public:
		template <typename T>
		class WriteAccess {
			friend class Bridge;
			T& value;

		public:
			WriteAccess(T& val) : value(val) {}

			T& operator()() {
				return value;
			}
		};

		Bridge(const Configuration& config) 
			: gps(createGps(config, WriteAccess<SystemCoordinates>(coordinates))
			, imu(createImu(config, WriteAccess<SystemKinetics>(kinetics))
			, wind(createWind(config, WriteAccess<SystemWind>(wind)) 
		{
			if (!gps)
				throw std::runtime_error("GPS module not started");

			if (!imu)
				throw std::runtime_error("IMU module not started");

			if (!wind)
				throw std::runtime_error("Wind module not started");

		}
	};
}
