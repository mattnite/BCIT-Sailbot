// Arbitrary Polygon on a spherical surface
//
// Author: Matthew Knight
// File Name: polygon.hpp
// Date: 2019-05-02

#pragma once

#include "point.hpp"
#include "bounding-box.hpp"

#include <algorithm>

namespace Sailbot::Navigation {
	/**
	 * The polygon is represented by a ring of points. The first and last points
	 * are connected by a point.
	 */
	class Polygon {
		std::vector<Point> points;
		BoundingBox box;

	public:
		Polygon(std::vector<Point>&& points) 
			: points(points) 
			, box({
				std::max_element(
					points.begin(), 
					points.end(), 
					[](auto& a, auto& b) {
						return a.latitude() > b.latitude();
					}
				)->latitude(),
				std::min_element(
					points.begin(), 
					points.end(), 
					[](auto& a, auto& b) {
						return a.longitude() < b.longitude();
					}
				)->longitude(),
			}, {
				std::max_element(
					points.begin(), 
					points.end(), 
					[](auto& a, auto& b) {
						return a.latitude() < b.latitude();
					}
				)->latitude(),
				std::min_element(
					points.begin(), 
					points.end(), 
					[](auto& a, auto& b) {
						return a.longitude() > b.longitude();
					}
				)->longitude(),
			})
		{}

		const BoundingBox& boundingBox() const noexcept {
			return box;
		}
	};
}
