// Pathfinding Program

// Author: Matthew Knight
// Date: 2016-12-20

// This program uses the A* algorithm to optimize the best path from a beggining
// Node to and end node given a list of obstacles.

#include <stdio.h>			
#include <unistd.h>			// For getopt()
#include <stdlib.h>
#include "../include/cpp/node.h"
#include "../include/stack.h"
#include "../include/pathList.h"
#include <iostream>


// Function for converting coordinate string into integer coordinates
int coordToInt(char *str, int *x, int *y);

int main(int argc, char *argv[])
{
    // Variables for holding arguments
    char *obstStr = NULL;
    int c;
    char *end;

    // Make sure number of arguments is correct
    if (argc > 5)
    {
	printf("Error: Too many arguments\n");
	return -1;
    }
    
    if (argc <= 2)
    {
	printf("Error: Not enough arguments\n");
	return -2;
    }
    
    // Parse Arguments
    while( (c = getopt(argc, argv, "e:f:")) != -1)
    {
	switch (c)
	{
	case 'e':
	    end = optarg;
	    break;
	case 'f':
	    obstStr = optarg;
	    break;
	}
    }
    
    int endX, endY;
    coordToInt(end, &endX, &endY);
    
    // Initialize Lists
    LinkedList obs;
    PathList open, closed(endX, endY);

    // Add beginning node (always origin)
    closed.add(0, 0);

    // Let's load up those Obstacles
    if (obstStr)
    {
	FILE *obstFile = fopen(obstStr, "r");
	int maxBuf = 80;		// Typical buffer size
	char buffer[maxBuf];
	while (fgets(buffer, maxBuf, obstFile))
	{
	    // Convert string to int
	    int obsX, obsY;		// ints to hold coordinates
	    coordToInt(buffer, &obsX, &obsY);
	    obs.add(obsX, obsY);
	}
	
	fclose(obstFile);
    }
    
    // A* is done when the end point is added to the closed list
    while (!closed.findEnd())
    {
	// The last node added to the closed list
	PathNode *cur = closed.last();

	// evaluate nodes around
	int i, j;
	for (i = cur->x - 1; i < cur->x + 2; i++)	
	    for (j = cur->y - 1; j < cur->y + 2; j++)
		    if (!obs.find(i, j))
			if (!obs.find(i, cur->y))
			    if (!obs.find(cur->x, j))
				if (!closed.find(i, j))
				    if(!open.find(i, j))
					open.add(i, j, cur);
				    else
					open.costEval(i, j, cur);
	
	// transfer open to closed
	open.transfer(open.cheapest(), closed);
    }

    // Initialize stack and find end node
    Stack path;
    PathNode *endNode = closed.findEnd();

    // pushing to the stack
    for (; endNode->parent; endNode = endNode->parent)
	    path.push(endNode->x, endNode->y);

    // Pop and print
    for(!path.empty())
    {
	cout << path.x() << "," << path.y() << endl;
	path.pop();
    }
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

