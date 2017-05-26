// Complex class testing

#include <iostream>
#include <complex>
#include <cmath>
#include "../include/vect.hpp"

using namespace std;

// [m^2/s] Kinetic viscosity of air at sealevel
const double v = 1.460e-5;		

int main (void)
{

    const double c = 0.6096;		// [m] chord length
    double V, R;
    
    V = 7.7;			// [m/s] air velocity
    R = (V*c)/v;

    cout << "Reynold's number: " << R << endl;

}
