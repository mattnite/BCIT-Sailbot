// Record base class
//
// Author: Matthew Knight
// File Name: record.hpp
// Date: 2019-04-24

#pragma once

#include "polygon.hpp"

#include <iostream>
#include <vector>
#include <cstdint>

namespace Sailbot::Navigation::ShapeFile {
	/**
	* Parses the record header
	*/
	class Record {
		uint32_t number;
		uint32_t length;
		std::vector<char> buf;

	public:
		Record(std::istream& is);
		
		uint32_t getNumber() const noexcept;
		
		uint32_t getLength() const noexcept;

		std::vector<Polygon> extractPolygons();
	};
}
