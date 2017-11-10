// Sailbot data types header

// Author: Matthew Knight
// File Name: sailbotTypes.h
// Date: 2017-08-11

// This header contains structures used in the sailbot control system shared
// memory segments.

#ifndef SAILBOTTYPES_H_
#define SAILBOTTYPES_H_

// Server shm
struct serverData
{
    int mode;				// Manual(0)/Auto(1) mode
    int cflag;				// Clear flag
    double rudder;			// Manual rudder position
    double aileron;			// Manual aileron position
};

// GPS shm
struct gpsData
{
    double lon;				// Longitude
    double lat;				// Latitude
    double lon_err;			// Longitude error [m]
    double lat_err;			// Latitude error [m]
} gpsData;

// IMU shm
struct imuData
{
    double heading;			// Current heading [degrees]
    double linAcc[3];			// Linear Acceleration (no gravity)
    double quat[3];			// orientation [quaturnions]
};

// Wind shm
struct windData
{
    double speed;			// Wind speed [m/s]
    double direction;			// Wind Direction [degrees]
};

// Linear Actuator shm
struct linActData
{
    double rudder;			// Desired rudder position (-1 to 1)
    double aileron;			// Desired aileron position (-1 to 1)
};

#endif
