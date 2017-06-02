// foil Simulation Interface File

// Author: Matthew Knight
// File Name: foil.hpp
// Date: 2017-05-25

// These classes are used to model the foils on the wingsail. Air conditions
// assume to be at sea level.

#ifndef SAIL_H_
#define SAIL_H_

#include <complex>
#include "LUT.hpp"

class foil
{
    LUT cl;				// look up tables for lift and drag
    LUT cd;
    
    double s;				// wing area
    double c;				// chord length
public:
    //ctor
    foil(
	double area,			// wing area
	double chord			// chord length
    );
    
    // Calculate force vector
    std::complex<double> force(
	std::complex<double> wind		// Wind velocity vector
	
    );
};

#endif
