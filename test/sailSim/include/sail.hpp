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
public:
    std::complex<float> wind;		// variable for holding last wind read

    // The foils
    foil main;				// Main foil, NACA0018
    foil aileron;			// Aileron foil, NACA0009
    
    // Rotational mechanics
    float J;				// Moment of interia
    float b;				// Angular friction 
    float d;				// Distance between pivot points
    float tD;				// angle between aileron and main
    float theta;			// angle of wingsail
    float w;				// angular velocity
    float a;				// angular acceleration
public:
    //ctor
    sail();

    // get force vector
    std::complex<float> force();

    // update for time interval
    void update (
	std::complex<float>& windVect,
	float ang,			// New angle of aileron wrt main
	float t
    );
};

#endif
