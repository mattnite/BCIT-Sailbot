// Module factory methods
//
// Author: Matthew Knight
// File Name: factories.hpp
// Date: 2019-04-12

#pragma once

#include "gps.hpp"
#include "imu.hpp"
#include "wind.hpp"

namespace Sailbot {
	GpsPtr createGps(Bridge& bridge);
	ImuPtr createImu(Bridge& bridge);
	WindPtr createWind(Bridge& bridge);
}
