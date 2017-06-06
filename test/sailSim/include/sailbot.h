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
    float v;				// Velocity magnitude
    float a;				// acceleration
    float J;				// Moment of Inertia
    float br;				// rotational water drag coefficient
    float kr;				// Rudder Coefficient
    float dt;				// Time period of system    
    float xPos;				// Last 2 x coordinates
    float yPos;				// Last 2 y coordinates

    // Sail Implementation
    float mass;				// mass of boat
    float bl;				// linear water drag coefficient
    float kw;				// Wind speed to force coefficient

public:
    // ctor
    sailbot(
	float time,			// Time period of system
	float initHead,			// Initial Heading
	float vel,			// Initial Velocity
	float rudderK,			// Rudder coefficient
	float mInteria,			// Moment of intertia
	float wDragR,			// Rotational water drag coefficient
	float wDragL,			// Linear water drag coefficient
	float initX,			// Initial Coordinates
	float initY
    );

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
