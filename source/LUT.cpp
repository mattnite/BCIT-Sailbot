// C++ Look up table class implementation file

// Author: Matthew Knight
// File Name: LUT.cpp
// Date: 2017-05-29

// This class is a 2 dimensional lookup table using Bilinear Interpolation. All
// the data is importeed from a csv file.

#include <fstream>
#include <vector>
#include <string>

using namespace std;

// ctor
LUT::LUT(string fileName)
{
    // Open File
    ifstream inFile(fileName);

    // Read first line, 
    // first element is name string, 
    // count columns, i
    
    // initialize column vector, 
    col = vector<double> (colNum, 0);
    // fill it up.
    
    // Go through entire file and count lines

    // initialize row and data vector
    row = vector<double> (rowNum, 0);
    data = vector<double> (rowNum, vector<double> (colNum, 0));

    // go to second line

    // first element goes to row vector, rest go to first row of data vector

    // loop through and repeat for entire file

    // close file
    inFile.close();
};

// interpolate 
double LUT::interp(double x, double y)
{
    return 0.0;
};
