// Node Implemetation File

// Author: Matthew Knight
// Date: 2016-11-12

// This file contains functions used for the A* Algorithm using linked lists
#include <stdlib.h>
#include <math.h>
#include "node.h"

// Global Var
int endX = 0;
int endY = 0;

// Create Node and return pointer
Node *createNode(
)
{
    // Allocate memory and then set up node
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->next = NULL;
    temp->data = NULL;
    return temp;
}

// Function for deallocating memory taken up by the node objects in list
int freeList(
    Node *list				// List of nodes to deallocate
)
{
    while(list != NULL)
    {
	Node *hold = list->next;
	free(list->data);
	free(list);
	list = hold;
    }

    return 0;
}

// Function to transfer a node from one list to another
int transferNode(
    Node *transfer,			// Node to transfer 
    Node *listFrom,			// Node list to transfer from
    Node *listTo			// Node list to transfer to
)
{
    // parse through ListFrom
    while (listFrom->next != transfer)
    {
	// if node is not in list
	if (!listFrom)
	    return -2;
	listFrom = listFrom->next;
    }

    listFrom->next = transfer->next;
    transfer->next = NULL;

    // parse to end of listTo
    while (listTo->next)
	listTo = listTo->next;
    listTo->next = transfer;
    
}

// Function for adding a node to a list
int addNode(
    Node *list,
    Node *parent,
    int xPos,				// X coordinate
    int yPos				// Y coordinate
)
{
    // Error if Null
    if (!list)
	return -1;
    
    // Allocate and initialize data
    Node *added = createNode();
    PathNode *newData = (PathNode*)malloc(sizeof(PathNode));
    newData->x = xPos;
    newData->y = yPos;
    newData->parent = parent;
    added->data = newData;
    
    // Find end of list
    while(list->next != NULL)
	list = list->next;

    // Append to end of list
    list->next = added;

    // Evaluate Cost
    costEval(list, xPos, yPos, NULL);
}

// Evaluate cost of a node
int costEval(
    Node *list, 
    int xPos, 
    int yPos, 
    Node *newParent
)
{
    Node *evalNode;
    // First check if node is in the list
    if (!(evalNode = (Node*)findNode(list, xPos, yPos)));
	return -1;

    // Load up data
    PathNode *temp = (PathNode*)evalNode->data;

    // If the parent is Null, exit (we don't care)
    if (!temp->parent)
	return 0;

    PathNode* nodeData;

    // check if we will be comparing with current costs
    if (newParent)
	nodeData = (PathNode*)newParent->data;	
    else
	nodeData = (PathNode*)temp->parent->data;
	
    // Evaluate costs
    int gCost = nodeData->g;
    
    // Diagonal move or Orthogonal
    if (temp->x != nodeData->x && temp->y != nodeData->y)
	gCost += 14;
    else
	gCost += 10;

    int difX = abs(temp->x - endX);
    int difY = abs(temp->y - endY);
    int diag = min(difX, difY);
    int hCost = 14*diag + difX + difY - 2*diag;
    
    // Later: THE Algorithm goes here
    int fCost = gCost + hCost;
    
    // exit if the old cost is greater
    if (newParent && fCost < temp->f)
	return 0;
    
    // update
    temp->g = gCost;
    temp->h = hCost;
    temp->f = fCost;

    return 0;
}

// Find out if a node exists within a list, return pointer is found, else return
// NULL.
Node *findNode(
    Node *list, 
    int xPos, 
    int yPos
)
{    
    // If the node is in the list, return true
    while (list->next != NULL)
    {
	// if Node is non-empty, we check it out
	if (list->data != NULL)
	{
	    PathNode *temp = (PathNode*)list->data;
	
	    // If it matches, then we're golden
	    if (temp->x == xPos && temp->y == yPos)
		return list;
	}
	// Let's check out the next guy
        list = list->next;
	
    }

    // It isn't, so return NULL
    return NULL;
}
