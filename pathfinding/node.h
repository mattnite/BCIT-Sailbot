// Linked List Interface File

// Author: Matthew Knight
// Date: 2016-11-12

// This file contains the interface for the linked list structure used to 
// implement the A* Algorithm

#ifndef NODE_H_
#define NODE_H_

// Generic node structure for linked lists
typedef struct Node_
{
    struct Node_ *next;				// Next node in list
    void *data;				// Generic pointer to element
} Node;

// Element of a path node linked list
typedef struct PathNode_
{
    Node *parent;			// Pointer to parent node
    int x;				// X position
    int y;				// Y position
    int g;				// G cost
    int h;				// H cost
    int f;				// F cost
} PathNode;

// Initialize Node or List
Node *createNode();

// Function for deallocating memory taken up by the node objects in list
int freeList(Node *list);

// Function to transfer a node from one list to another
int transferNode(Node *transfer, Node *listFrom, Node *listTo);

// Function for adding a node to a list with specific coordinates
int addNode(Node *list, Node *parent, int xPos, int yPos);

// Re-evaluates the cost of a node, points the node to the current visited
int costEval(Node *list, int xPos, int yPos, Node *newParent);

// Tells you if a node exsists within a list
Node *findNode(Node *list, int xPos, int yPos);

#endif
