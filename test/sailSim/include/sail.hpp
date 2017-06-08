// Wing Sail Interface File

// Author: Matthew Knight
// File Name: sail.hpp
// Date: 2017-05-31

// This class is used to simulate the wingsail.

#ifndef SAIL_H_
#define SAIL_H_

#include <complex>
#include <vector>
#include "foil.hpp"

class sail
{
    double t;				// Simulation time interval

    // The foils
    foil main;				// Main foil, NACA0018
    foil aileron;			// Aileron foil, NACA0009
    
    // Rotational mechanics
    double J;				// Moment of interia
    double b;				// Angular friction 
    double d;				// Distance between pivot points
    double tD;				// angle between aileron and main
    double theta;			// angle of wingsail
    double w;				// angular velocity
    double a;				// angular acceleration
public:
    //ctor
    sail();

    // get force vector
    std::complex<double> force(
	std::complex<double> wind	// Wind vector
    );

    // update for time interval
    void update (
	double rate			// angular velocity of aileron in rad/s
    );
};

#endif
