// Wing Sail Implementation File

// Author: Matthew Knight
// File Name: sail.cpp
// Date: 2017-06-8

// This class is used to simulate the wingsail.

#include "sail.hpp"
#include "vect.hpp"

#define PLEN 0.4191			// [m] Distance between pivots

//ctor
sail::sail()
    : t(0.1)
    , J(0.843)
    , b(1.186)
    , d(0.4191)
    , tD(0.0)
    , theta(0.0)
    , w(0.0)
    , a(0.0)
    , wind(0.0, 0.0)
    , main("naca0018", 0.6096, 1.3)
    , aileron("naca0009", 0.2286, 0.209)
{};

// get force vector
std::complex<double> sail::force()	// Wind vector
{
    return rotate(main.force(abs(wind), arg(wind) - theta), theta);
}

// update for time interval
void sail::update(std::complex<double> &windVect, double ang)		
{
    // Update values
    wind = windVect;
    tD = ang;

    // Determine angle of attack
    double alpha = arg(wind) - (tD + theta);

    // Get force from aileron
    std::complex<double> F = rotate(aileron.force(alpha, abs(wind)), theta + tD);

    // Find Torque
    double T = dot(F, std::polar(PLEN, theta));

    // update knematics
    a = T/J;
    w += a*t;
    theta += w*t;
}
