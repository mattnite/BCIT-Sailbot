// C++ Look up table class interface file

// Author: Matthew Knight
// File Name: LUT.hpp
// Date: 2017-05-26

// This class is a 2 dimensional lookup table using Bilinear Interpolation. All
// the data is importeed from a csv file.

#include <iostream>
#include <fstream>
#include <list>
#include <string>

class LUT
{
    string file;
    string name;
    list<double> x, y;
    list< list<double> > data;

public:
    // ctor
    LUT(string file);

    // interpolate 
    double interp(double xPos, double yPos);
};
