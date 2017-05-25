// Complex class testing

#include <iostream>
#include <complex>
#include <cmath>

using namespace std;

// normal of a complex number
template <typename T>
complex<T> normal(complex<T> a);

// dot product
template <typename T>
T dot(complex<T> a, complex<T> b);

// Projection
template <typename T>
complex<T> project(complex<T> a, complex<T> b);

// Vector rotation
template <typename T>
complex<T> rotate(complex<T> a, double beta);

// [m^2/s] Kinetic viscosity of air at sealevel
const double v = 1.460e-5;		

class foil
{
    complex<double> a;			// direction of airfoil
    double s;				// wing area
    double c;				// chord length
public:
    //ctor
    foil(
	double theta,			// angle of foil
	double area,			// wing area
	double chord			// chord length
    );

    calcLift(
	double w,			// wind velocity vector

    );
};

class wingSail
{
    foil main;				// main foil component
    foil aileron;			// aileron component
};
int main (void)
{

    const double c = 0.6096;		// [m] chord length
    double V, R;
    
    V = 7.7;			// [m/s] air velocity
    R = (V*c)/v;

    cout << "Reynold's number: " << R << endl;

}


// normal of a complex number
template <typename T>
complex<T> normal(complex<T> a)
{
    complex<T> b(real(a)/abs(a), imag(a)/abs(a));
    return b;
};

// dot product
template <typename T>
T dot(complex<T> a, complex<T> b)
{
    return (real(a)*real(b)) + (imag(a)*imag(b));
};

// Projection
template <typename T>
complex<T> project(complex<T> a, complex<T> b)
{
   return (dot(a, b)/abs(b))*normal(b);
};

// Vector rotation
template <typename T>
complex<T> rotate(complex<T> a, double beta)
{
    double c = cos(beta);
    double s = sin(beta);
    complex <T> b((real(a)*c) - (imag(a)*s), (real(a)*s) + (imag(a)*c));
    return b;
};
