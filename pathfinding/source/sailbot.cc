// Sailbot Simulation Class Interface File

// Author: Matthew Knight
// Date: 2016-12-25

// This class models the sailbot, the inputs are the rudder and aileron
// position and wind speed and direction

#include <math.h>
#include <stdio.h>
#include "sailbot.h"

// ctor
sailbot::sailbot(
    float time, 
    float initHead, 
    float vel, 
    float rudderK, 
    float mInertia,
    float waterDrag,
    float initX,
    float initY
)
:dt(time), velocity(vel), kr(rudderK), J(mInertia), b(waterDrag)
{
    // Initialize heading
    thetaH[0] = initHead*(M_PI/180);
    thetaH[1] = initHead*(M_PI/180);
    thetaH[2] = initHead*(M_PI/180);

    // Initialize position
    xPos[0] = initX;
    xPos[1] = initX;
    yPos[0] = initY;
    yPos[1] = initY;
}

// advance the sailbot by one time period
void sailbot::advance(float rudder)
{
    // saturate input
    rudder = saturate(rudder, 1);
    
    // Roll back values:
    thetaH[2] = thetaH[1];
    thetaH[1] = thetaH[0];
    xPos[1] = xPos[0];
    yPos[1] = yPos[0];

    
    // New Theta Value
    thetaH[0] = (1/(b*dt + J))*((b*dt + 2*J)*thetaH[1] - J*thetaH[2] 
	+ (rudder*velocity*kr*dt*dt));

    if (thetaH[0] > M_PI)
    {
	thetaH[0] -= 2*M_PI;
	thetaH[1] -= 2*M_PI;
	thetaH[2] -= 2*M_PI;
    }
    if (thetaH[0] <= -M_PI)
    {
	thetaH[0] += 2*M_PI;
	thetaH[1] += 2*M_PI;
	thetaH[2] += 2*M_PI;
    }
    // New coordinate values
    xPos[0] = xPos[1] + dt*velocity*sinf(thetaH[0]);
    yPos[0] = yPos[1] + dt*velocity*cosf(thetaH[0]);

}

// return heading
float sailbot::heading()
{
    return thetaH[0];
}

// return x Position
float sailbot::x()
{
    return xPos[0];
}

// return y Position
float sailbot::y()
{
    return yPos[0];
}

// Saturate a value
float sailbot::saturate(float val, float max)
{
    if (val > max)
	return max;
    if (val < -max)
	return -max;
    return val;
}

