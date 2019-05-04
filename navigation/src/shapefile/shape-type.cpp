// Shape types string conversion
//
// Author: Matthew Knight
// File Name: shape-type.cpp
// Date: 2019-05-04

#include "shapefile/shape-type.hpp"

#include <iostream>

namespace Sailbot::Navigation::ShapeFile {
	std::ostream& operator<<(std::ostream& os, ShapeType type) {
		switch (type) {
			case ShapeType::NullShape:
				os << "NullShape";
				break;
			case ShapeType::Point:
				os << "Point";
				break;
			case ShapeType::PolyLine:
				os << "PolyLine";
				break;
			case ShapeType::Polygon:
				os << "Polygon";
				break;
			case ShapeType::MultiPoint:
				os << "Multipoint";
				break;
			case ShapeType::PointZ:
				os << "PointZ";
				break;
			case ShapeType::PolyLineZ:
				os << "PolyLineZ";
				break;
			case ShapeType::PolygonZ:
				os << "PolygonZ";
				break;
			case ShapeType::MultiPointZ:
				os << "MultiPointZ";
				break;
			case ShapeType::PointM:
				os << "PointM";
				break;
			case ShapeType::PolyLineM:
				os << "PolyLineM";
				break;
			case ShapeType::PolygonM:
				os << "PolygonM";
				break;
			case ShapeType::MultiPointM:
				os << "MultiPointM";
				break;
			case ShapeType::MultiPatch:
				os << "MultiPatch";
				break;
			default:
				os << "Unknown";
				break;
		}

		return os;
	}
}
