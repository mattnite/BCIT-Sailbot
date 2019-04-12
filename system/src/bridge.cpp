
#include "bridge.hpp"

namespace Sailbot {
	void Bridge::setCoordinates(const Gps::Coordinates& coord) {
		coordinates = Measurement<Gps::Coordinates>(coord);	
	}

	Gps::Coordinates Bridge::getCoordinates() {
		return coordinates.load();
	}
}


/*
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
		*/
