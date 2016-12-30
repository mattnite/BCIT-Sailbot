// Sailbot Simulation

// Author: Matthew Knight
// Date: 2016-12-25

#include <stdio.h>
#include <math.h>
#include "sailbot.h"

int main (void)
{
    float dt = 0.1;
    float initHeading = 0;
    float initVel = 1;
    float turnRate = 1;
    float mInertia = 1;
    float waterDrag = 1;
    float xPos = -1, yPos = -1;
    sailbot bcit(dt, initHeading, initVel, turnRate, mInertia, waterDrag, xPos, yPos);
    int i, n = 100;
    float rudder = 1;
    for (i = 0; i < n; i++)
    {
	printf("Rudder: %f Heading: %f X: %f Y: %f\n", rudder, bcit.heading()*(180/M_PI), bcit.x(), bcit.y());
	bcit.advance(rudder);

    }
}
