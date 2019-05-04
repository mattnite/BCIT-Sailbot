// Shape types
//
// Author: Matthew Knight
// File Name: shape-type.hpp
// Date: 2019-05-04

#pragma once

#include <iostream>

namespace Sailbot::Navigation::ShapeFile {
	enum class ShapeType : uint32_t {
		NullShape = 0,
		Point = 1,
		PolyLine = 3,
		Polygon = 5,
		MultiPoint = 8,
		PointZ = 11,
		PolyLineZ = 13,
		PolygonZ = 15,
		MultiPointZ = 18,
		PointM = 21,
		PolyLineM = 23,
		PolygonM = 25,
		MultiPointM = 28,
		MultiPatch = 31
	};

	std::ostream& operator<<(std::ostream& os, ShapeType type);
}
