// Node Interface File

// Author: Matthew Knight
// Date: 2016-11-12

// This file contains the interface for the linked list structure used to 
// implement the A* Algorithm

#ifndef NODE_H_
#define NODE_H_

// Defines for node lists
#define END 0
#define PRO 1
#define VIS 2
#define OBS 3
#define PTH 4

// This Node structure makes up the linked lists for the A* algorithm
typedef struct Node
{
    Node* next;				// Next node in list
    Node* last;				// Last node in A* algorithm
    int x;				// X position of node
    int y;				// Y position of node
    float cost;				// Cost of node
} node;

extern Node* mesh[5];

// Function for deallocating memory taken up by the node objects in list
int freeList(Node* list);

// Function to transfer a node from one list to another
int transferNode(Node* transfer, Node* listFrom, Node* listTo);

// Function for adding a node to a list with specific coordinates
int addNode(Node** list, int xPos, int yPos);

// Re-evaluates the cost of a node, points the node to the current visited
int costCheck(Node* list, int xPos, int yPos, Node* pointTo);

// Tells you if a node exsists within a list
bool findNode(Node* list, int xPos, int yPos);

#endif
