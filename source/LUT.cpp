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

// default ctor
LUT::LUT()
{};

// ctor
LUT::LUT(const char *file)
:fileName(file), rowNum(0), colNum(0)
{
    // Open File
    std::ifstream inFile(file);

    // Read first line, 
    std::string buf;
    std::stringstream line;
    getline(inFile, buf);
    line.str(buf);
    
    // first element is name string, 
    getline(line, name, ',');
   
    // fill column vector
    for (;getline(line, buf, ','); colNum++)	
	col.push_back(strtod(buf.c_str(), NULL));
    
    // fill row and data vectors
    for (;getline(inFile, buf); rowNum++)
    {
	line.clear();
	line.str(buf);
	getline(line, buf, ',');
	row.push_back(strtod(buf.c_str(), NULL));
		
	std::vector<double> dataLine;

	while (getline(line, buf, ','))
	    dataLine.push_back(strtod(buf.c_str(), NULL));
	
	data.push_back(dataLine);
    }
    
    inFile.close();
};

// interpolate 
double LUT::interp(double x, double y)
{
    // Find interpolation points
    int i, j;

    for (i = 1; i < rowNum; i++)
	if (row[i] > x)
	    break;

    for (j = 1; j < colNum; j++)
	if (col[j] > y)
	    break;
    
    // Load up values
    double m = 1/((row[i] - row[i-1])*(col[j] - col[j-1]));
    
    double a[] = {  row[i] - x,
		    x - row[i-1]};
    
    double b[] = {  col[j] - y,
		    y - col[j-1]};
   
    double c[][2] = {{	data[i-1][j-1], 
			data[i-1][j]}, 
		    {	data[i][j-1], 
			data[i][j]}};
    
    double val = 0;
    
    // calculate
    for (i = 0; i<2; i++)
	for (j = 0; j<2; j++)
	    val += a[i]*b[j]*c[i][j];
    
    return val*m;    
};
