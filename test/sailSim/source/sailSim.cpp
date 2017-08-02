// Sail Simulation Program

// Author: Matthew Knight
// File Name: sailSim.cpp
// Date: 2017-06-08

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <complex>
#include "sail.hpp"

int main(void)
{
    // Create our environment and apparatus
    std::complex<double> wind = std::polar(10.0, 0.0);
    sail wingSail;
    double time = 0.0;

    std::clog 
	<< "Interval Period: " << wingSail.t << "s" << std::endl << std::endl
	<< "Starting Simulation..." << std::endl << std::endl;

    for (; time < 5.0; time += wingSail.t)
    {
	wingSail.update(wind, 0.1);
	std::complex<double> force = wingSail.force();
	std::cout
	    << time << ","
	    << wingSail.theta << ","
	    << real(force) << ","
	    << imag(force) << std::endl;
    }

    std::clog << std::endl << "Simulation Complete" << std::endl << std::endl;
}
