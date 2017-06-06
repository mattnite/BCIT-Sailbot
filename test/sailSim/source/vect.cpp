// Complex class Vector Functions

// Author: Matthew Knight
// File Name: vect.cpp
// Date: 2017-05-25

// doublehese functions are mostly for use in simulating the sailbot

#include <complex>
#include <cmath>
#include "vect.hpp"

// normal of a complex number
std::complex<double> normal(std::complex<double> a)
{
    std::complex<double> b(real(a)/abs(a), imag(a)/abs(a));
    return b;
};

// dot product
double dot(std::complex<double> a, std::complex<double> b)
{
    return (real(a)*real(b)) + (imag(a)*imag(b));
};

// Projection
std::complex<double> project(std::complex<double> a, std::complex<double> b)
{
   return (dot(a, b)/abs(b))*normal(b);
};

// Vector rotation
std::complex<double> rotate(std::complex<double> a, double beta)
{
    double c = cos(beta);
    double s = sin(beta);
    std::complex <double> b((real(a)*c) - (imag(a)*s), 
	(real(a)*s) + (imag(a)*c));
    return b;
}
