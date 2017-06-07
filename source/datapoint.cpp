// Datapoint class implementation file

// Author: Matthew Knight
// File Name: datapoint.cpp
// Date: 2017-06-07

// The purpose of this class is to keep track of when variables are changed.
// That way if there are errors, or a process is locked up, other threads know
// when a variable is old.

#include <chrono>

using namespace std::chrono;

template <typename T>

// ctor
datapoint::datapoint()
{

}

// Assigning new value
void datapoint::operator=(T newdata)
{

}

// getting value
T datapoint::operator=(datapoint<T> point)
{

}

// return when variable was recoded
system_clock::time_point datapoint::timestamp()
{

}
