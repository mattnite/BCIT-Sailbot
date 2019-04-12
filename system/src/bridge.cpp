
#include "bridge.hpp"

namespace Sailbot {
		Bridge::Bridge()
			: gps(createGps(*this))
			, imu(createImu(*this))
			, wind(createWind(*this))
		{
			if (!gps)
				throw std::runtime_error("GPS module not started");

			if (!imu)
				throw std::runtime_error("IMU module not started");

			if (!wind)
				throw std::runtime_error("Wind module not started");

		}
	void Bridge::setCoordinates(const Gps::Coordinates& coord) {
		coordinates = Measurement<Gps::Coordinates>(coord);	
	}

	Gps::Coordinates Bridge::getCoordinates() {
		return coordinates.load();
	}


	
