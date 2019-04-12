// Sailbot types header
// Author: Matthew Knight
// File Name: 2019-04-11

#pragma once

#include "gps.hpp"
#include "imu.hpp"
#include "measurement.hpp"
#include "wind.hpp"

#include <atomic>
#include <memory>

namespace Sailbot {
	class Gps;
	class Imu;
	class Wind;
	
	using GpsPtr = std::shared_ptr<Gps>;
	using ImuPtr = std::shared_ptr<Imu>;
	using WindPtr = std::shared_ptr<Wind>;

	using SystemCoordinates = std::atomic<Measurement<Gps::Coordinates>>;
	using SystemKinetics = std::atomic<Measurement<Imu::Data>>;
	using SystemWind = std::atomic<Measurement<Wind::Data>>;
}
