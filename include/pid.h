// PID Controller interface File

// Author: Matthew Knight
// Date: 2016-12-21

// This module allows for the implemenation of PID Control loops.

class pid
{
    float kp;				// Proportional Constant
    float ki;				// Integrator Constant
    float kd;				// Derivitave Constant
    float dt;				// Time period
    float intSat;			// Integrator Saturation value
    float integrator;			// integrator value
    float eLast;			// last error input
    float outVal;			// Holds the output value
public:
    // ctor
    pid(float time, float saturate, float kP, float kI, float kD);

    // Advance the pid one time constant
    void advance(float e);

    // Change system constants
    void tune(float kP, float kI, float kD, float saturate);

    // return the output
    float out();

private:
    // Apply saturation to value
    float saturate(float val, float max);
};

class fode
{
    float k;				// Gain of the system
    float T;				// Time period of the system
    float dt;				// Time period  of discrete system
    float lastOut;			// Last output value
    float outVal;			// Holds output value

public:
    // ctor
    fode(float time, float gain, float period);

    // advance system by one time period
    void advance(float in);

    // return output value
    float out();
};
