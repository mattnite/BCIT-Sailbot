// Look up table test program

#include <iostream>
#include "../include/LUT.hpp"

using namespace std;

int main (void)
{
    const char *file = "../source/naca0009_lift.csv";
    LUT sailData(file);

    cout << sailData.fileName << endl
	<< sailData.name << endl
	<< "Rows: " << sailData.rowNum << endl
	<< "Columns: " << sailData.colNum << endl << endl;

    double alpha = 5.25, R = 1100000;
    cout 
	<< "Alpha: " << alpha << " Degrees" << endl
	<< "Reynold's Number: " << R << endl
	<< "Lift Coefficient:" << sailData.interp(alpha, R) << endl;
}
