// Wind Sensor Interface
//
// Author: Matthew Knight
// Date: 2019-03-22
// File Name: wind.hpp

#pragma once

namespace Sailbot {
	/**
	 * @brief Wind Sensor Interface
	 *
	 * This class provides the interface for difference wind sensor
	 * implementations, this way different real sensors can be tested, or a
	 * simulation sensor can be used.
	 *
	 * The purpose of the wind sensor is to update the Bridge with the most
	 * up-to-date wind measurements.
	 */
	class Wind {
	public:
		// Positive directions are east and north respectively
		using Readings = std::complex<double>;
}
