// C++ Look up table class implementation file

// Author: Matthew Knight
// File Name: LUT.cpp
// Date: 2017-05-29

// This class is a 2 dimensional lookup table using Bilinear Interpolation. All
// the data is importeed from a csv file.

#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdlib>
#include "LUT.hpp"

#define strLen 256

// ctor
LUT::LUT(const char *file)
:fileName(file), rowNum(0), colNum(0)
{
    // Open File
    std::ifstream inFile(file);

    // Read first line, 
    std::string line, buf;
    getline(inFile, line);
    std::stringstream lineStream(line);

    // first element is name string, 
    getline(lineStream, name, ',');
   
    // fill column vector
    for (;getline(lineStream, buf, ','); colNum++)	
	col.push_back(strtod(buf.c_str(), NULL));
    
    // fill row and data vectors
    for (;getline(inFile, line); rowNum++)
    {
	getline(lineStream, buf, ',');
	row.push_back(strtod(buf.c_str(), NULL));
	
	std::vector<double> dataLine;

	while (getline(lineStream, buf, ','))
	    dataLine.push_back(strtod(buf.c_str(), NULL));

	data.push_back(dataLine);
    }
    
    inFile.close();
};

// interpolate 
double LUT::interp(double x, double y)
{
    // Find interpolation points
    int i j;
    for (i = 0; i < rowNum; i++)
	if (row[i] > x)
	    break;

    for (j = 0; j < colNum; j++)
	if (col[j] > y)
	    break;

    cout
};
