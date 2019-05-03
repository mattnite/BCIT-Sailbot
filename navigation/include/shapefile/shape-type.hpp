#pragma once

#include <iostream>

namespace Sailbot::Navigation {
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
