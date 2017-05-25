// Sail Simulation Interface File

// Author: Matthew Knight
// File Name: sail.hpp
// Date: 2017-05-25

// These classes are used to model the wingsail on the sailbot. Air conditions
// assume to be at sea level.

#ifndef SAIL_H_
#define SAIL_H_

#include <complex>

using namespace std;

class foil
{
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

    calcLift(
	double w,			// wind velocity vector

    );
};

class wingSail
{
    foil main;				// main foil component
    foil aileron;			// aileron component
};

#endif
