// Complex class testing

#include <iostream>
#include <complex>
#include <vector>
#include <cmath>
#include "../include/vect.hpp"

using namespace std;

// [m^2/s] Kinetic viscosity of air at sealevel

int main (void)
{
    vector<double> a (4, 1.0);

    vector< vector<double> > b (4, vector<double> (5, 1.0));
    cout << b[0][0] << endl;


}
