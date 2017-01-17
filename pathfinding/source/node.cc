// Node Implementation File

// Author: Matthew Knight
// Date: 2016-12-31

// The Node class is a simple class for containing information on a node for A*
// pathfinding. These are intended for use within different data structures such
// as linked lists, stacks, and queues, which entails a pointer to the next
// node and then x and y coordinates as private members. This base class can be
// utilized for keeping track of nodes and then the derived class PathNode is
// specifically used for A* implementation. As the pathfinding algorithm is
// tailored for sailing, the PathNode class members may change.

#include <stdlib.h>
#include "../include/cpp/node.h"

// ctor
Node::Node(int xPos, int yPos)
:x(xPos), y(yPos), next(NULL)
{}

// dtor
Node::~Node()
{}

// ctor
PathNode::PathNode(int xPos, int yPos, Node *par)
:Node(xPos, yPos), parent(par) 
{}

// dtor
PathNode::~PathNode()
{}

