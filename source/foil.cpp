// Sail Simulation Implementation File

// Author: Matthew Knight
// File Name: sail.cpp
// Date: 2017-05-25

// These classes are used to model the wingsail on the sailbot. Air conditions
// assume to be at sea level.

#include <complex>
#include <cmath>
#include "sail.hpp"
#include "vect.hpp"

const double v = 1.460e-5;		// [m^2/s] Kinetic viscosity of air at
					// sealevel
const double d = 1.225;			// [kg/m^3] Mass Density of air


//ctor
foil::foil( double area, double chord):
s(area), c(chord)
{};

// Calculate force vector in newtons
std::complex<double> foil::force(
    double alpha,			// [Deg.] angle of attack
    double vel				// [m/s] Relative flow velocity
)
{
    double val = 0.5*d*pow(vel, 2)*s;
    double R = vel*c/v;			// Reynold's number
    double beta = alpha*(180.0/M_PI);	// convert to degrees
    
    // Calculate Lift and drag Forces
    std::complex<double> Fr;
    Fr.real = val*cl.interp(alpha, R);
    Fr.imag = val*cd,intero(alpha, R);

    // right the lift direction
    if (alpha < 0)
	Fr.imag *= -1;

    // Rotate to proper position
    rotate(Fr, alpha);

    return Fr;
};
