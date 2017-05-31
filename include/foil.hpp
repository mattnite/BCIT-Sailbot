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

using namespace std;

class foil
{
    LUT cLift;				// look up tables for lift and drag
    LUT cDrag;
    
    complex<double> a;			// direction of airfoil
    double s;				// wing area
    double c;				// chord length
public:
    //ctor
    foil(
	double theta,			// angle of foil
	double area,			// wing area
	double chord			// chord length
    );
    
    void turn(
	double r			// rotate foil in r degrees
    );

    // Calculate force vector
    complex<double> force(
	complex<double> wind		// Wind velocity vector
    );
};

#endif
