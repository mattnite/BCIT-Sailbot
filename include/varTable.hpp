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
    const char *gpsPort;
    const char *gpsCommPort;

    // Sampling periods (ms)
    datapoint<int> Tgps;
    datapoint<int> Timu;
    datapoint<int> Twind;
    datapoint<int> Tlin;

    // Wind Vars
    datapoint<double> windSpeed;
    datapoint<double> windDir;

    // GPS vars
    datapoint< tuple<double,double> > pos; 
    datapoint< tuple<double,double> > error;

    // IMU vars
    datapoint< tuple<double,double,double> > quat;
    datapoint< tuple<double,double,double> > linAcc;
    datapoint<double> heading;

    // Setpoints (-1 to 1)
    datapoint<double> ailOut;
    datapoint<double> rudOut;

// Methods
    // ctor
    varTable();
};

#endif
