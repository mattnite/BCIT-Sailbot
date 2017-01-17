// PathList Interface File

// Author: Matthew Knight
// Date: 2012-12-30

// The PathList is a linked list tailored for A* pathfinding. Since it is
// intended that different heuristic methods be tested, another base class
// algorithm will be defined in order to generalize the process.

#ifndef PATHLIST_H_
#define PATHLIST_H_

#include "node.h"

// Linked List
class LinkedList
{
    Node* first;

public:
    // ctor
    LinkedList();
    
    // add node to list
    int add(int xPos, int yPos);

    // Find a node and return a reference to it
    Node virtual *find(int xPos, int yPos);

    // Find las node
    Node virtual *last();

    // dtor
    ~LinkedList();
};

// PathList Class
class PathList : public LinkedList
{
    int endX;				// End Node Coordinates
    int endY;
    float windDir;			// Wind direction (0 = N,90 = E,-90 = W)
    float windSpd;			// Wind Speed
    float initHeading;			// Current Heading of sailbot
    float initVel;			// Current Velocity of sailbot

public:
    // ctor
    PathList(int ex = 0, int ey = 0, float wd = 0, float ws = 0, float ih = 0, 
	float iv = 0);
      
    // Add PathNode
    int add(int xPos, int yPos, PathNode* parent = NULL);

    // Transfer Node to a different List
    int transfer(PathNode *send, PathList &dest);

    // Evaluate Cost of a Node
    int costEval(int xPos, int yPos, PathNode* parent);
   
    // Return pointer to cheapest node
    PathNode *cheapest();

    // Determine if End node is in list
    PathNode *findEnd();

    // dtor
    ~PathList();
};

#endif
