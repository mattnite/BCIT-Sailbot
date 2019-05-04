// Bounding box class
// 
// Author: Matthew Knight
// File Name: bounding-box.hpp
// Date: 2019-04-25

#pragma once

#include "point.hpp"

namespace Sailbot::Navigation {
	struct BoundingBox {
		Point tl;
		Point br;

		BoundingBox() = default;

		BoundingBox(const Point& tl, const Point& br) : tl(tl), br(br) {}
	};
}
