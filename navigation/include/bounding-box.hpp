// Bounding box class
// 
// Author: Matthew Knight
// File Name: bounding-box.hpp
// Date: 2019-04-25

#pragma once

#include "point.hpp"

class BoundingBox {
	Point tl;
	Point br;

public:
	BoundingBox(const Point& tl, const Point& br) : tl(tl) br(br) {}

	const Point& topLeft() const noexcept {
		return tl;
	}

	const Point& bottomRight const noexcept {
		return br;
	}
};
