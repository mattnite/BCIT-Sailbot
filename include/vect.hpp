// Complex class Vector Functions

// Author: Matthew Knight
// File Name: vect.hpp
// Date: 2017-05-25

// These functions are mostly for use in simulation of the sailbot

#ifndef VECT_H_
#define VECT_H_

#include <complex>

// normal of a complex number
template <typename T>
std::complex<T> normal(std::complex<T> a);

// dot product
template <typename T>
T dot(complex<T> a, std::complex<T> b);

// Projection
template <typename T>
std::complex<T> project(std::complex<T> a, std::complex<T> b);

// Vector rotation
template <typename T>
std::complex<T> rotate(std::complex<T> a, double beta);

#endif
