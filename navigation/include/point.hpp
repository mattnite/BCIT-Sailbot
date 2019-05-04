// Point class for navigation
//
// Author: Matthew Knight
// File Name: point.hpp
// Date: 2019-04-25

#pragma once

namespace Sailbot::Navigation {
	struct Point {
		double latitude;
		double longitude;

		Point() = default;

		Point(double lat, double lon) noexcept 
			: latitude(lat)
			, longitude(lon)
		{}
	};
}
