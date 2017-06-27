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

using namespace std::chrono;

class varTable
{
public:
    // System constants
    const char *gpsPort;
    const char *gpsCommPort;

    // Sampling periods (ms) (100 - 10000)
    std::atomic<int> Tgps;

    // Wind Vars


    // GPS vars
    std::atomic< tuple<double,double> > pos; 
    
    // IMU vars

    // Wingsail Vars

    // Rudder Vars

    // Setpoints (-1 to 1)
    std::atomic<double> ailOut;
    std::atomic<double> rudOut;

// Methods
    // ctor
    varTable();
};

#endif
