// Node Interface File

// Author: Matthew Knight
// Date: 2016-11-12

// This file contains the interface for the linked list structure used to 
// implement the A* Algorithm

#include <ncurses.h>			// For the ncurses environment
#include <time.h>
#include <stdlib.h>			// rand()
#include <math.h>			// sqrt()

// Defines for node lists
#define END 0
#define PRO 1
#define VIS 2
#define OBS 3
#define PTH 4

typedef struct Node
{
    Node* next;				// Next node in list
    Node* last;				// Last node in A* algorithm
    int x;				// X position of node
    int y;				// Y position of node
    float cost;				// Cost of node
} node;

static Node* mesh[4] = {    NULL, 
			    NULL, 
			    NULL,
			    NULL    };

// Create Node and return pointer
Node* createNode(int xPos, int yPos);

// Function for deallocating memory taken up by the node objects in list
int freeList(Node* list);

// Function to transfer a node from one list to another
int transferNode(Node* transfer, Node* listFrom, Node* listTo);

// Function for adding a node to a list
int addNode(Node** list, int xPos, int yPos);

// Checks cost of a node 
int costCheck(Node* list, int xPos, int yPos, Node* pointTo);

// Tells you if a node exsists within a list
bool findNode(Node* list, int xPos, int yPos);

