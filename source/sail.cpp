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

// [m^2/s] Kinetic viscosity of air at sealevel
const double v = 1.460e-5;	    
const double d = 1.225;			// [kg/m^3] Mass Density of air

using namespace std;

// FOIL CLASS

//ctor
foil::foil( double theta, double area, double chord):
a(polar(1.0, theta)), s(area), c(chord)
{};

void foil::turn(double r)
{
    // convert to radians and rotate counter clockwise
    double ang =  r*(M_PI/180.0);
    a = rotate(a, ang);
};


// Calculate force vector
complex<double> foil::force(
    complex<double> vel		// Relative flow velocity vector
)
{
    double val = 0.5*d*pow(abs(vel), 2)*s;
    
    // Calculate Lift and drag coefficients via table lookup
    double lift = 1.0;
    double drag = 1.0;

    // Calculate lift and Drag Forces
    lift *= val;
    drag *= val;

    // Orient them in the right direction
    double liftAng;
    if ( arg(vel) > arg(a))
	liftAng = arg(vel) - M_PI;
    else
	liftAng = arg(vel) + M_PI;

    return drag*normal(vel) + polar(lift, liftAng);
};

// WINGSET CLASS
