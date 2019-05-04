// Record base class
//
// Author: Matthew Knight
// File Name: record.cpp
// Date: 2019-04-24

#include "shapefile/record.hpp"

#include "point.hpp"
#include "polygon.hpp"
#include "shapefile/endian.hpp"
#include "shapefile/shape-type.hpp"

#include <iostream>
#include <vector>

namespace Sailbot::Navigation::ShapeFile {
	Record::Record(std::istream& is) {
		extract<Endian::Big>(is, number);
		extract<Endian::Big>(is, length);
		length *= 2;

		buf.resize(length - sizeof(number) - sizeof(length));
		is.read(buf.data(), buf.size());
	}
	
	uint32_t Record::getNumber() const noexcept {
		return number;
	}
	
	uint32_t Record::getLength() const noexcept {
		return length;
	}

	std::vector<Polygon> Record::extractPolygons() {
		std::vector<Polygon> polygons;
		ShapeType type;
		uint32_t numParts;
		uint32_t numPoints;

		extract<Endian::Little>(buf, type);
		if (type != ShapeType::Polygon)
			throw std::runtime_error("record is not a polygon");
		
		buf.erase(buf.cbegin(), std::next(buf.cbegin(), 32));
		extract<Endian::Little>(buf, numParts);
		extract<Endian::Little>(buf, numPoints);

		std::vector<uint32_t> parts(numParts);
		std::vector<Point> points(numPoints);

		for (auto& part : parts)
			extract<Endian::Little>(buf, part);
	
		uint32_t last = 0;
		for (auto& part : parts) {
			std::vector<Point> points(part - last);
			
			for (auto& point : points) {
				extract<Endian::Little>(buf, point.latitude);
				extract<Endian::Little>(buf, point.longitude);
			}

			polygons.emplace_back(std::move(points));
			last = part;
		}

		return polygons;
	}
}
