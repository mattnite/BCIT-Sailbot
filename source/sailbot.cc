// Sailbot Simulation Class Interface File

// Author: Matthew Knight
// Date: 2016-12-25

// This class models the sailbot, the inputs are the rudder and aileron
// position and wind speed and direction

#include <math.h>
#include <stdio.h>
#include "../include/sailbot.h"

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
:dt(time), v(vel), kr(rudderK), J(mInertia), br(wDragR), xPos(initX), 
    yPos(initY), a(0)
{
    // Initialize heading
    thetaH[0] = initHead*(M_PI/180);
    thetaH[1] = initHead*(M_PI/180);
    thetaH[2] = initHead*(M_PI/180);
}

// advance the sailbot by one time period
void sailbot::advance(float rudder, float aileron, float ws, float wd)
{
    // saturate input
    rudder = saturate(rudder, 1);
    aileron = saturate(aileron, 1); 
     
    // Roll back values:
    ThetaH[2] = ThetaH[1];
    ThetaH[1] = ThetaH[0];

    // Calculate acceleration
    float Fw; 
    wd = wd*(M_PI/180);			    // Convert to radians
    if (wd - ThetaH[0] < 85*(M_PI/180) || wd - ThetaH[0] > -85*(M_PI/180))
	Fw = kw*ws*cosf(wd - thetaH[0]);
    else
	Fw = aileron*ws*kw*cosf(wd - thetaH[0] - M_PI);
    a = (Fw/m) - (bl/m)*v;

    // Velocity
    v = v + a*dt;

    // New Theta Value
    thetaH[0] = (1/(b*dt + J))*((b*dt + 2*J)*thetaH[1] - J*thetaH[2] 
	+ (rudder*v*kr*dt*dt));

    if (thetaH[0] > M_PI)
	for (int i = 0; i < 3; i++)
	    thetaH[i] -= 2*M_PI;
    
    if (thetaH[0] <= -M_PI)
	for (int i = 0; i < 3; i++)
	    thetaH[i] += 2*M_PI;
   
    // New coordinate values
    xPos = xPos + dt*v*sinf(thetaH[0]);
    yPos = yPos + dt*v*cosf(thetaH[0]);

}

// return acceleration
float sailbot::acc()
{
    return a;
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
