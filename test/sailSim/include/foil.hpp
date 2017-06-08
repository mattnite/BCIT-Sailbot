// Foil Simulation Interface File

// Author: Matthew Knight
// File Name: foil.hpp
// Date: 2017-05-25

// These classes are used to model the foils on the wingsail. Air conditions
// assume to be at sea level.

#ifndef FOIL_H_
#define FOIL_H_

#include <complex> 
#include "LUT.hpp"

class foil
{
    LUT cl;				// look up tables for lift and drag
    LUT cd;
    
    double s;				// wing area
    double c;				// chord length
public:
    // default ctor
    foil();
    
    //ctor
    foil(
	const char *name,
	double area,			// wing area
	double chord			// chord length
    );
    
    // Calculate force vector
    std::complex<double> force(
	double alpha,			// angle of attack
	double vel			// Wind velocity
    );
};

#endif
