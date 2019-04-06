// System variable table implementation file

// Author: Matthew Knight
// File Name: varTable.cpp
// Date: 2017-06-05

// This class contains all the system variables in the sailbot. It is intended
// that the task threads in the control system have access to these atomic
// variables and operate on them.

#include <array>
#include <atomic>
#include "varTable.hpp"

varTable::varTable()
    : gpsPort("5555")
    , gpsCommPort("5554")
{}

// ACCESSOR METHODS - Self explanitory

// Wind Speed
double varTable::getWindSpeed()
{
    return windSpeed;
}

int varTable::setWindSpeed(double newSpeed)
{
    //windSpeed = newSpeed;

    return 0;
}

// Wind Direction
double varTable::getWindDir()
{
    return windDir;
}

int varTable::setWindDir(double newDir)
{
    //windDir = newDir;
    
    return 0;
}

// GPS Location
std::array<double,2> varTable::getPosition()
{
    return pos;
}

int varTable::setPosition(double lat, double lon)
{
    return 0;
}

// GPS Error
std::array<double,2> varTable::getError()
{
    return error;
}

int varTable::setError(double newLatErr, double newLonErr)
{

    return 0;
}

// Orientation in Quaternions
std::array<double,3> varTable::getQuat()
{
    return quat;
}

int varTable::setQuat(double i, double j, double k)
{

    return 0;
}

// Linear Acceleration
std::array<double,3> varTable::getAcc()
{
    return linAcc;
}

int varTable::setAcc(double x, double y, double z)
{

    return 0;
}

// Heading
double varTable::getHeading()
{
    return heading;
}

int varTable::setHeading(double newHead)
{
    heading = newHead;

    return 0;
}
