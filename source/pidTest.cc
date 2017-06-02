// PID Control of a sailbot

// Author: Matthew Knight
// Date: 2016-12-24

// This program is for testing the c++ pid module for the sailbot

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "../include/pid.h"
#include "../include/sailbot.h"
#include "../include/queue.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Convert coordinate string to integers
int coordToInt(char *str, int *x, int *y);

int main (void)
{
    // Wind data
    float windSpd = 1;
    float windDir = -135;
     
    
    float dt = 0.01;
    sailbot bcit(dt, 45, 1, 1, 1, 1, 0, 0);
    pid rudder(dt, 1, 2, 0, 1);
    pid aileron(dt, 1, 1, 0, 0);
    float nWid = 5, nLen = 5;
    
    
    float setpoint;
    float error;
    int count = 0; 
    
    // Initialize Queue
    Queue path;
    
    // Load values from file
    ifstream pathFile;    
    pathFile.open("path.csv", ios::in);
    if (pathFile.is_open())
    {
	while (!pathFile.eof())
	{
	    char *coord;
	    int x,y;
	    pathFile >> coord;
	    coordToInt(coord, &x, &y);
	    path.add(x,y);
	}
    }
    else
	cerr << "Could not open path file" << endl;
    pathFile.close();

    // Initialize coordinate setpoints
    float xSet = nWid*path.getX();
    float ySet = nLen*path.getY();
    
    // Main Loop, limit to 10000
    while (count < 10000)
    {
	// Check to see if it's within the node
	if (bcit.x() >= xSet - (0.5*nWid) && bcit.x() < xSet + (0.5*nWid))
	{
	    if (bcit.y() >= ySet - (0.5*nLen) && bcit.y() < ySet + (0.5*nLen))
	    {	
		path.next();
		if (path.empty())
		    return 0;
		xSet = nWid*path.getX();
		ySet = nLen*path.getY();
	    }
	}	

	// Which direction does it need to be?
	setpoint = (atan2((xSet-bcit.x()),(ySet - bcit.y())))*(180/M_PI);
	
	// How far off are we?
	float hError = (setpoint - bcit.heading()*(180/M_PI));
	
	// Roll heading value to keep between -180 and 180
	if (hError > 180)
	    hError -= 360;
	if (hError <= -180)
	    hError += 360;
	
	// Datalog new line
	cout << count++*dt << "," 
	    << bcit.acc() << ","
	    << bcit.x() << "," 
	    << bcit.y() << ","
	    << setpoint << "," 
	    << bcit.heading()*(180/M_PI) << "," 
	    << rudder.out() << endl;
	
	// normalize error so that it's from -1 to 1, this is for the pid loop
	hError = hError/180;

	aileron.advance(aError);
	rudder.advance(hError);
	bcit.advance(rudder.out(), aileron.out(), windSpd, windDir);
    }

    return 0;
}

// Function for converting coordinate string into integer coordinates
int coordToInt(
    char *str,				// Ptr to coordinate str
    int *x,				// Ptr to X int
    int *y				// Ptr to Y int
)
{
    char *yStr;				// Holds Y coord str

    *x = strtol(str, &yStr, 10);
    *y = strtol(yStr + 1, NULL, 10);
}

