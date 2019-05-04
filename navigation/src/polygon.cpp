// Arbitrary Polygon on a spherical surface
//
// Author: Matthew Knight
// File Name: polygon.cpp
// Date: 2019-05-02

#include "polygon.hpp"
#include "point.hpp"
#include "bounding-box.hpp"

#include <algorithm>

namespace Sailbot::Navigation {
	Polygon::Polygon(std::vector<Point>&& points) 
		: points(points) 
	{
		auto lat = std::minmax_element(
			points.cbegin(), 
			points.cend(), 
			[](auto& a, auto& b) { return a.latitude < b.latitude; }
		);

		auto lon = std::minmax_element(
			points.cbegin(),
			points.cend(),
			[](auto& a, auto& b) { return a.longitude < b.longitude; }
		);

		box.tl.latitude = lat.first->latitude;
		box.tl.longitude = lon.second->longitude;
		box.br.latitude = lat.second->latitude;
		box.br.longitude = lon.first->longitude;
	}

	const BoundingBox& Polygon::bounds() const noexcept {
		return box;
	}
}
