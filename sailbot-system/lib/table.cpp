// Table Structure
//
// Author: Matthew Knight
// File Name: table.cpp
// Date: 2018-10-10
//
// This structure holds the system data that different processes can manipulate.
// And this file simply holds the stream insertion operator

#include "table.hpp"

// stream insertion operator for a table class
std::ostream& operator<<(std::ostream &out, const Table &t) {
	out 
		<< t.coords.real() << ","
		<< t.coords.imag() << ","
		<< t.wind.real() << ","
		<< t.wind.imag() << ","
		<< t.heading.real() << ","
		<< t.heading.imag();
	return out;
}
