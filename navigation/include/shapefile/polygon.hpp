// Polygon record class
//
// Author: Matthew Knight
// File Name: record.hpp
// Date: 2019-04-24

#pragma once

#include "record.hpp"
#include "shape-type.hpp"

#include <array>
#include <vector>
#include <sstream>

namespace Sailbot::Navigation::ShapeFile {
	/**
	* Parses the polygon record
	*/
	class Polygon : public Record {
		BoundingBox box;
		uint32_t numParts;
		uint32_t numPoints;

		std::vector<uint32_t> parts;
		std::vector<uint32_t> points;

	public:
		Polygon(std::istream& is) : Record(is) {
			ShapeType type;
			extractEndian(Endian::Little, is, type);
			
			if (type != ShapeType::Polygon) {
				std::stringstream ss;
				ss << "Polygon was given type " << type;
				throw std::runtime_error(ss.str());
			}

			double xMin, xMax, yMin, yMax;
		
			extractEndian(Endian::Little, is, xMin);
			extractEndian(Endian::Little, is, yMin);
			extractEndian(Endian::Little, is, xMax);
			extractEndian(Endian::Little, is, yMax);

			box.set(xMin, yMin, xMax, yMax);

			extractEndian(Endian::Little, is, numParts);
			extractEndian(Endian::Little, is, numPoints);

			parts.resize(numParts);
			points.resize(numPoints*4);
			
			for (auto& part : parts)
				extractEndian(Endian::Little, is, part);

			for (auto& point : points)
				extractEndian(Endian::Little, is, point);
		}

		uint32_t getNumParts() {
			return numParts;
		}

		uint32_t getNumPoints() {
			return numPoints;
		}
	};
}
