// Complex class Vector Functions

// Author: Matthew Knight
// File Name: vect.cpp
// Date: 2017-05-25

// These functions are mostly for use in simulating the sailbot

#include <complex>
#include <cmath>
#include "../include/vect.hpp"

using namespace std;

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
