// foil Simulation Implementation File

// Author: Matthew Knight
// File Name: sail.cpp
// Date: 2017-05-25

// These classes are used to model the wingsail on the sailbot. Air conditions
// assume to be at sea level.

#include <iostream>
#include <complex>
#include <string>
#include <cmath>
#include "vect.hpp"
#include "foil.hpp"

const double v = 1.460e-5;		// [m^2/s] Kinetic viscosity of air at
					// sealevel
const double d = 1.225;			// [kg/m^3] Mass Density of air

// default ctor
foil::foil()
    : s(0)
    , c(0)
{};

//ctor
foil::foil( const char *name, double area, double chord)
    : s(area)
    , c(chord)
{
    // build strings out of name
    std::string lift(name);
    std::string drag(name);

    lift += "_lift.csv";
    drag += "_drag.csv";

    // construct look up tables
    cl = LUT(lift.c_str());
    cd = LUT(drag.c_str());

    // Print size of look up tables
    std::cout
	<< name << " Air Foil:" << std::endl
	<< "\tLift table size: " << cl.rowNum <<  ", " << cl.colNum <<std::endl
	<< "\tDrag table size: " << cd.rowNum <<  ", " << cd.colNum <<std::endl
	<< std::endl;
	
};

// Calculate force vector in newtons
std::complex<double> foil::force(
    double alpha,			// [rad] angle of attack
    double vel				// [m/s] Relative flow velocity
)
{
    double val = 0.5*d*pow(vel, 2)*s;
    double R = vel*c/v;			// Reynold's number
    double beta = alpha*(180.0/M_PI);	// convert to degrees

    if (beta < 0)
	beta *= -1;
    // Calculate Lift and drag Forces
    std::complex<double> Fr = val*
    	(cl.interp(beta, R),
	cd.interp(beta, R));

    // right the lift direction
    if (alpha < 0)
	Fr.imag(-1*Fr.imag());

    // Rotate to proper position
    Fr = rotate(Fr, alpha);

    return Fr;
};
