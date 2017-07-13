// System variable table class

// Author: Matthew Knight
// File Name: varTable.hpp
// Date: 2017-06-05

// This class contains all the system variables in the sailbot. It is intended
// that the task threads in the control system have access to these atomic
// variables and operate on them.

#ifndef VARTABLE_H_
#define VARTABLE_H_

#include <array>
#include "datapoint.hpp"

class varTable
{
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
    datapoint< std::array<double,2> > pos; 
    datapoint< std::array<double,2> > error;

    // IMU vars
    datapoint< std::array<double,3> > quat;
    datapoint< std::array<double,3> > linAcc;
    datapoint<double> heading;

public:
    // ctor
    varTable();

    // ACCESSOR METHODS - Self explanitory
    
    // Wind Speed
    double getWindSpeed();
    
    int setWindSpeed(double newSpeed);
    
    // Wind Direction
    double getWindDir();
    
    int setWindDir(double newDir);
    
    // GPS Location
    std::array<double,2> getPosition();
    
    int setPosition(double lat, double lon);
    
    // GPS Error
    std::array<double,2> getError();
    
    int setError(double newLatErr, double newLonErr);
    
    // Orientation in Quaternions
    std::array<double,3> getQuat();
    
    int setQuat(double i, double j, double k);
    
    // Linear Acceleration
    std::array<double,3>getAcc();
    
    int setAcc(double x, double y, double z);
    
    // Heading
    double getHeading();
    
    int setHeading(double newHead);
};

#endif
