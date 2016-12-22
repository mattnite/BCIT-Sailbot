// Pathfinding Program

// Author: Matthew Knight
// Date: 2016-12-20

// This program uses the A* algorithm to optimize the best path from a beggining
// Node to and end node given a list of obstacles.

#include <stdio.h>			
#include <unistd.h>			// For getopt()
#include <stdlib.h>
#include "node.h"

extern int endX;
extern int endY;

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
    coordToInt(end, &endX, &endY);
    
    // Initialize Lists
    Node *obs = (Node*)createNode();
    Node *open = (Node*)createNode();
    Node *closed = (Node*)createNode();
    
    // Add beginning node (always origin)
    addNode(closed, NULL, 0, 0);

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
	    addNode(obs, NULL, obsX, obsY);
	}
	
	fclose(obstFile);
    }
    
    // A* is done when the end point is added to the closed list
    while (!findNode(closed, endX, endY))
    {
	// find last closed node
	Node *current = closed;
	while (current->next != NULL)
	    current = current->next;

	PathNode *cData = (PathNode*)current->data;
	printf("Looking around (%d, %d)\n", cData->x, cData->y);	
	// evaluate nodes around
	int i, j;
	for (i = cData->x - 1; i < cData->x + 2; i++)	
	{
	    for (j = cData->y - 1; j < cData->y + 2; j++)
		{
		    if (!findNode(obs, i, j))
		    {
			if (!findNode(closed, i, j))
			{
			    if(!findNode(open, i, j))
			    {
				addNode(open, current, i, j);
				printf("open <- (%d, %d)\n", i, j);
			    }
			    else
			    {
				costEval(open, current, i, j);
			    }
			}
		    }
		}
	}
	
	// look for cheapest node
	char fFlag = 0;
	int cost;
	Node *lowest, *parser = open;
	
	// Check fCost
	for (cost = -1; parser->next != NULL; parser = parser->next)
	{
	  
	    if (parser->data)
	    {
		PathNode *check = (PathNode*)parser->data;
		if (check->f < cost || cost < 0)
		{
		    lowest = parser;
		    cost = check->f;
		    fFlag = 0;
		}
		if (check->f == cost)
		{
		    lowest = parser;
		    fFlag = 1;
		}
	    }
	}
	
	// Check hCost
	if (fFlag)
	{
	    cost = -1;
	    for (parser = open; parser->next != NULL; parser = parser->next)
	    {
		if (parser->data)
		{
		    PathNode *check = (PathNode*)parser->data;
		    if (check->h < cost || cost < 0)
		    {
			lowest = parser;
			cost = check->h;
		    }
		    if (check->f == cost)
			lowest = parser;
		}
		
	    }
	}

	// transfer open to closed
	transferNode(lowest, open, closed);
    }

    // Free the lists
    freeList(obs);
    freeList(open);
    freeList(closed);

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

