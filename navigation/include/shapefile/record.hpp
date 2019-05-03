// Record base class
//
// Author: Matthew Knight
// File Name: record.hpp
// Date: 2019-04-24

#pragma once

#include "endian.hpp"
#include <iostream>

/**
 * Parses the record header
 */
class Record {
	uint32_t number;
	uint32_t length;

public:
	Record(std::istream& is) {
		extractEndian(Endian::Big, is, number);
		extractEndian(Endian::Big, is, length);
		length *= 2;
	}
	
	uint32_t getNumber() {
		return number;
	}
	
	uint32_t getLength() {
		return length;
	}
};
