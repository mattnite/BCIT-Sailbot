// System variable table class

// Author: Matthew Knight
// File Name: varTable.hpp
// Date: 2017-06-05

// This class contains all the system variables in the sailbot. It is intended
// that the task threads in the control system have access to these atomic
// variables and operate on them.

#include <atomic>
#include <chrono>
#include <string>

using namespace std::chrono;

class varTable
{
    // System constants
    
    // Sampling periods (ms)
    std::atomic<int> Tgps;

    // Wind Vars


    // GPS vars
    std::atomic<double> lat, long;

    // IMU vars

    // Wingsail Vars

    // Rudder Vars

    // Setpoints
}
