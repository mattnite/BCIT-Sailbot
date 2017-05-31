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
	<< "Columns: " << sailData.colNum << endl;

    sailData.interp(5.0, 75000.0);
}
