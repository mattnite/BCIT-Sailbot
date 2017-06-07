// Datapoint class interface file

// Author: Matthew Knight
// File Name: datapoint.hpp
// Date: 2017-06-07

// The purpose of this class is to keep track of when variables are changed.
// That way if there are errors, or a process is locked up, other threads know
// when a variable is old.

#ifndef DATAPOINT_H_
#define DATAPOINT_H_

#include <chrono>

using namespace std::chrono;

template <typename T>
class datapoint
{
    T data;
    system_clock::time_point last;
public:
    // ctor
    datapoint();

    // Assigning new value
    void operator=(T newdata);

    // getting value
    T operator=(datapoint<T> point);

    // return when variable was recoded
    system_clock::time_point timestamp();
};

#include "datapoint.cpp"

#endif
