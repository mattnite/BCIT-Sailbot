// Sailbot Simulation Model

// Author: Matthew Knight
// File Name: sailbot.hpp
// Date: 2017-05-24

// This class models the sailbot, the inputs are the rudder and aileron
// position and wind speed and direction

#ifndef SAILBOT_H_
#define SAILBOT_H_

#include <complex>
#include <vector>

class sailbot
{
    // Dynamic variables
    complex<float> pos;			// position of the sailbot
    vector<float> heading;		// Heading in radians (last two as well)
    float v;
    float a;
    
    // Parametric Constants
    float mass;				// mass of boat
    float J;				// Moment of Inertia
    float br;				// rotational water drag coefficient
    float kr;				// Rudder Coefficient
    float dt;				// Time period of system    
    float bl;				// linear water drag coefficient
    float kw;				// Wind speed to force coefficient
    
    // The sail
    class sail;

public:
    // ctor
    sailbot();

    // advance the sailbot by one time period
    void advance(
	float rudder,			// Rudder position (-1 to 1)
	float aileron,			// aileron position (-1 to 1)
	float ws,			// wind speed
	float wd			// wind direction
    );

    // return acceleration
    float acc();

    // return heading
    float heading();

    // return x coordinate
    float x();

    // return y coordinate
    float y();

private:
    // Saturate a value
    float saturate(
	float val,			// Value to be saturated
	float max			// upper and lower limit of saturation
    );
};

#endif
