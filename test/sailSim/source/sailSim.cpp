// Sail Simulation Program

// Author: Matthew Knight
// File Name: sailSim.cpp
// Date: 2017-06-08
#include <iostream>
#include "sail.hpp"
#include "foil.hpp"
#include "LUT.hpp"
#include "vect.hpp"

int main(void)
{
    sail wingSail();
    foil test("naca0009", 1, 1);

    std::cout << test.force(0.1, 10) << std::endl;
}
