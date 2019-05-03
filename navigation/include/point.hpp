// Point class for navigation
//
// Author: Matthew Knight
// File Name: point.hpp
// Date: 2019-04-25

#pragma once

namespace Sailbot::Navigation {
	class Point {
		double lat;
		double lon;

	public:
		Point(double lat, double lon) noexcept : lat(lat), lon(lon) {}
		
		double longitude() const noexcept {
			return lon;
		}

		double latitude() const noexcept {
			return lat;
		}
	};
}
