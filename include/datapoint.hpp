// Datapoint interface file

// Author: Matthew Knight
// File Name: datapoint.hpp
// Date: 2017-06-27

// This file declares and defines a class for storing atomic variables and
// keeping track of when they were last updated.

#ifndef DATAPOINT_H_
#define DATAPOINT_H_

#include <atomic>
#include <chrono>

using namespace std::chrono;

// Datapoint class
template <typename T>
class datapoint
{
    std::atomic<T> data;
    system_clock::time_point sampTime;

public:
    // default ctor
    datapoint();
    
    // initialized ctor
    datapoint(T initVal);

    // operator overload
    void operator=(const T &val);

    // Loading data from datapoint class
    operator T() {return data.load();}
};

template <typename T>
datapoint<T>::datapoint()
:sampTime(std::chrono::system_clock::now())
{}

template <typename T>
datapoint<T>::datapoint(T initVal)
:sampTime(std::chrono::system_clock::now())
{
    data.store(initVal);
}

template <typename T>
void datapoint<T>::operator=(const T &val)
{
    // atomically store new value
    data.store(val);

    // update sample timepoint
    sampTime = std::chrono::system_clock::now();
}

#endif
