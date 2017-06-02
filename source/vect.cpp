// Complex class Vector Functions

// Author: Matthew Knight
// File Name: vect.cpp
// Date: 2017-05-25

// These functions are mostly for use in simulating the sailbot

#include <complex>
#include <cmath>
#include "vect.hpp"

// normal of a complex number
template <typename T>
std::complex<T> normal(std::complex<T> a)
{
    std::complex<T> b(real(a)/abs(a), imag(a)/abs(a));
    return b;
};

// dot product
template <typename T>
T dot(std::complex<T> a, std::complex<T> b)
{
    return (real(a)*real(b)) + (imag(a)*imag(b));
};

// Projection
template <typename T>
std::complex<T> project(std::complex<T> a, std::complex<T> b)
{
   return (dot(a, b)/abs(b))*normal(b);
};

// Vector rotation
template <typename T>
std::complex<T> rotate(std::complex<T> a, double beta)
{
    double c = cos(beta);
    double s = sin(beta);
    std::complex <T> b((real(a)*c) - (imag(a)*s), (real(a)*s) + (imag(a)*c));
    return b;
}

