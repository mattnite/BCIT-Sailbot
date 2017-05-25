// Complex class Vector Functions

// Author: Matthew Knight
// File Name: vect.hpp
// Date: 2017-05-25

// These functions are mostly for use in simulation of the sailbot

#ifndef VECT_H_
#define VECT_H_

#include <complex>

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

#endif
