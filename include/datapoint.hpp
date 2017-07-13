// Datapoint interface file

// Author: Matthew Knight
// File Name: datapoint.hpp
// Date: 2017-06-27

// This file declares and defines a class for storing atomic variables and
// keeping track of when they were last updated.

#ifndef DATAPOINT_H_
#define DATAPOINT_H_

#include <chrono>
#include <mutex>
using namespace std::chrono;

// Datapoint class
template <typename T>
class datapoint
{
    std::mutex mtx;
    T data;
    system_clock::time_point sampTime;

public:
    // default ctor
    datapoint();
    
    // initialized ctor
    datapoint(T initVal);

    // milliseconds since last update
    int time_since();

    // operator overload
    void operator=(const T &val);

    // Loading data from datapoint class
    operator T();
};

template <typename T>
datapoint<T>::datapoint()
:sampTime(system_clock::now())
{}

template <typename T>
datapoint<T>::datapoint(T initVal)
:sampTime(system_clock::now())
{
    std::lock_guard<std::mutex> lck(mtx);
    data = initVal;
}

template <typename T>
int datapoint<T>::time_since()
{
    milliseconds period = system_clock::now() - sampTime;
    return period.count();
}

template <typename T>
void datapoint<T>::operator=(const T &val)
{
    std::lock_guard<std::mutex> lck(mtx);
    
    // store new value and update timestamp
    data = val;
    sampTime = std::chrono::system_clock::now();
}

template <typename T>
datapoint<T>::operator T()
{
    std::lock_guard<std::mutex> lck(mtx);
    return data; 
}

#endif
