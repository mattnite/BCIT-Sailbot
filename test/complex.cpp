// Complex class testing

#include <iostream>
#include <complex>
#include <cmath>
#include "../include/vect.hpp"

using namespace std;

// [m^2/s] Kinetic viscosity of air at sealevel

int main (void)
{
    complex<double> a, b, c;

    a = polar(1.0, 0.75);
    b = polar(1.0, 0.6);
    c = polar(1.0, 0.9);
    
    cout << b - a << endl
	<< arg(b) - arg(a) << endl
	<< c - a << endl
	<< arg(c) - arg(a) << endl;



}
