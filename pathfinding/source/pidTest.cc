// PID Control of a sailbot

// Author: Matthew Knight
// Date: 2016-12-24

// This program is for testing the c++ pid module for the sailbot

#include <stdio.h>
#include <math.h>
#include "pid.h"
#include "sailbot.h"
#include "queue.h"
#include "node.h"

int main (void)
{
    float dt = 0.01;
    sailbot bcit(dt, 45, 1, 1, 1, 1, 0, 0);
    pid rudder(dt, 1, 2, 0, 1);
    float nWid = 5, nLen = 5;
    float xNode = 4, yNode = -3;
    float xSet, ySet;
    float setpoint;
    float error;
    
    // Initialize Queue
    Node *queue = createNode(); 
    
    addToQueue(queue, 4, -3);
    
    xNode = getNextX(queue);
    yNode = getNextY(queue);
    advanceQ(queue);

    int n = 5000;
    int i;
    for (i = 0; i < n; i++)
    {
	xSet = xNode*nWid;
	ySet = yNode*nLen;

	// Check to see if it's within the node
	if (bcit.x() >= xSet - (0.5*nWid) && bcit.x() < xSet + (0.5*nWid))
	{
	    if (bcit.y() >= ySet - (0.5*nLen) && bcit.y() < ySet + (0.5*nLen))
	    {
		if (queue->next == NULL)
		    return 0;
		xNode = getNextX(queue);
		yNode = getNextY(queue);
		advanceQ(queue);
	    }
	}	

	
	setpoint = (atan2((xSet-bcit.x()),(ySet - bcit.y())))*(180/M_PI);
	
	error = (setpoint - bcit.heading()*(180/M_PI));
	if (error > 180)
	    error -= 360;
	if (error <= -180)
	    error += 360;
	
	printf("%f,%f,%f,%f,%f,%f\n", i*dt, bcit.x(), bcit.y(), setpoint, bcit.heading()*(180/M_PI), rudder.out());

	error = error/180;

	rudder.advance(error);
	bcit.advance(rudder.out());
    }

}
