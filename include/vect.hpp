// Complex class Vector Functions

// Author: Matthew Knight
// File Name: vect.hpp
// Date: 2017-05-25

// doublehese functions are mostly for use in simulation of the sailbot

#ifndef VECdouble_H_
#define VECdouble_H_

// normal of a complex number
std::complex<double> normal(std::complex<double> a);

// dot product
double dot(std::complex<double> a, std::complex<double> b);

// Projection
std::complex<double> project(std::complex<double> a, std::complex<double> b);

// Vector rotation
std::complex<double> rotate(std::complex<double> a, double beta);

#endif
