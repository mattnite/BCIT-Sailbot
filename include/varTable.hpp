// System variable table class

// Author: Matthew Knight
// File Name: varTable.hpp
// Date: 2017-06-05

// This class contains all the system variables in the sailbot. It is intended
// that the task threads in the control system have access to these atomic
// variables and operate on them.

#ifndef VARTABLE_H_
#define VARTABLE_H_

#include <atomic>
#include <chrono>
#include <string>
#include "datapoint.hpp"

using namespace std::chrono;

class varTable
{
public:
    // System constants
    
    // Sampling periods (ms)
    std::atomic< duration<int, std::milli> > Tgps;

    // Wind Vars


    // GPS vars
    std::atomic<double> lat, lon;

    // IMU vars

    // Wingsail Vars

    // Rudder Vars

    // Setpoints

// Methods
    // ctor
    varTable();



};

#endif
