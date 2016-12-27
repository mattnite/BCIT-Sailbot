// Sailbot Simulation Class Interface File

// Author: Matthew Knight
// Date: 2016-12-25

// This class models the sailbot, the inputs are the rudder and aileron
// position and wind speed and direction

#ifndef SAILBOT_H_
#define SAILBOT_H_

class sailbot
{
    float thetaH[3];			// Current and last two headings
    float velocity;			// Velocity magnitude
    float J;				// Moment of Inertia
    float b;				// water drag coefficient
    float kr;				// Rudder Coefficient
    float dt;				// Time period of system    
    float xPos[2];			// Last 2 x coordinates
    float yPos[2];			// Last 2 y coordinates

public:
    // ctor
    sailbot(
	float time,			// Time period of system
	float initHead,			// Initial Heading
	float vel,			// Initial Velocity
	float rudderK,			// Rudder coefficient
	float mInteria,			// Moment of intertia
	float waterDrag,		// Water drag coefficient
	float initX,			// Initial Coordinates
	float initY
    );

    // advance the sailbot by one time period
    void advance(
	float rudder			// Rudder position (-1 to 1)
    );

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

    // Keep angle between 0 and 2pi
    float normalizeAngle(
	float angle			// angle to be normalized
    );
};

#endif
