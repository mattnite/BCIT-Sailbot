// Node Class Interface File

// Author: Matthew Knight
// Date: 2016-12-30

// The Node class is a simple class for containing information on a node for A*
// pathfinding. These are intended for use within different data structures such
// as linked lists, stacks, and queues, which entails a pointer to the next
// node and then x and y coordinates as private members. This base class can be
// utilized for keeping track of nodes and then the derived class PathNode is
// specifically used for A* implementation. As the pathfinding algorithm is
// tailored for sailing, the PathNode class members may change.

#ifndef NODE_H_
#define NODE_H_

// Base Node Class
class Node
{
public:
    Node *next;				// Next node in whatever data structure
    int x;				// X coordinate
    int y;				// Y coordinate

    // ctor
    Node(int xPos, int yPos);

    // dtor
    ~Node();
};

// Derived PathNode class used for A* pathfinding
class PathNode : public Node
{
public:
    PathNode* parent;			// Pointer to parent
    int g;				// G cost of Node
    int h;				// H cost of Node
    int f;				// F cost of Node

    // ctor
    PathNode(int xPos, int yPos, Node *par);

    // dtor
    ~PathNode();
};

#endif
