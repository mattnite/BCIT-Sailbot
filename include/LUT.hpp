// C++ Look up table class interface file

// Author: Matthew Knight
// File Name: LUT.hpp
// Date: 2017-05-26

// This class is a 2 dimensional lookup table using Bilinear Interpolation. All
// the data is importeed from a csv file.

#ifndef LUT_H_
#define LUT_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class LUT
{
public:
    const char *fileName;
    std::string name;
    int rowNum, colNum;
    std::vector<double> row, col;
    std::vector< std::vector<double> > data;

    // Default ctor
    LUT();

    // ctor
    LUT(const char *file);
    
    // interpolate 
    double interp(double x, double y);
};

#endif
