// PID Controller Implementation File

// Author: Matthew Knight
// Date: 2016-12-22

// This module allows for the implemenation of PID control loops

#include "pid.h"

// ctor
pid::pid(float time, float saturate, float kP, float kI, float kD)
:dt(time), intSat(saturate), kp(kP), ki(kI), kd(kD), integrator(0), eLast(0), outVal(0)
{}

// Advance the pid one time constant
void pid::advance(float e)
{
    // Keep input between -1 and 1
    e = saturate(e, 1);
    
    // Activate the integrator
    integrator = integrator + (dt/2)*(e + eLast);
    integrator = saturate(integrator, intSat);

    float derivative = (e - eLast)/dt;
    outVal = kp*e + ki*integrator + kd*derivative;
    outVal = saturate(outVal, 1);
    eLast = e;
}

// Change system constants
void pid::tune(float kP, float kI, float kD, float saturate)
{
    kp = kP;
    ki = kI;
    kd = kD;
    intSat = saturate;
}

// return the output
float pid::out()
{
    return outVal;
}

// Apply saturation to value
float pid::saturate(float val, float max)
{
    if (val > max)
	return max;
    if(val < -max)
	return -max;
    return val;
}

// First Order Differential Equation Class

// ctor
fode::fode(float time, float gain, float period)
:dt(time), k(gain), T(period), outVal(0), lastOut(0)
{}

// advance system by one period
void fode::advance(float in)
{
    outVal = (1/(dt + T))*(T*lastOut + (k*dt)*in);
    lastOut = outVal;
}

// return output value
float fode::out()
{
    return outVal;
}
