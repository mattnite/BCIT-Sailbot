// Wing Sail Implementation File

// Author: Matthew Knight
// File Name: sail.cpp
// Date: 2017-06-8

// This class is used to simulate the wingsail.

#include "sail.hpp"

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
    , main("naca0018", 0.6096, 1.3)
    , aileron("naca0009", 0.2286, 0.209)
{};

// get force vector
std::complex<double> sail::force(std::complex<double> wind)	// Wind vector
{
    return wind;
}

// update for time interval
void sail::update(double ang)		// new aileron angle in rad
{
    
}
