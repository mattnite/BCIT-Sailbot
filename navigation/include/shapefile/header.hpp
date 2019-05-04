// Shapefile header class
//
// Author: Matthew Knight
// File Name: header.hpp
// Date: 2019-05-03

#pragma once

#include "shapefile/shape-type.hpp"
#include "bounding-box.hpp"

#include <iostream>
#include <cstdint>

namespace Sailbot::Navigation::ShapeFile {
	struct Header {
		uint32_t code;
		uint32_t length;
		uint32_t version;
		ShapeType type;
		BoundingBox box;

	public:
		Header(std::istream& is);
	};
}
