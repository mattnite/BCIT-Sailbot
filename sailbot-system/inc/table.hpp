// Table Structure
//
// Author: Matthew Knight
// File Name: table.hpp
// Date: 2018-10-10
//
// This structure holds the system data that different processes can manipulate

#ifndef TABLE_HPP
#define TABLE_HPP

#include <complex>
#include <iostream>

struct Table {
	std::complex<double> coords, wind, heading;
	friend std::ostream& operator<<(std::ostream &out, const Table &t);
};

#endif // TABLE_HPP
