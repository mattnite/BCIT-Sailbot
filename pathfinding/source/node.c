// Node Implemetation File

// Author: Matthew Knight
// Date: 2016-11-12

// This file contains functions used for the A* Algorithm using linked lists
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "node.h"

// Global Var
int endX = 0;
int endY = 0;

// Returns minimum integer
int min(int a, int b);

// Returns maximum integer
int max(int a, int b);

// Returns absolute of integer
int abs(int a);

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
    while (list != NULL)
    {
	Node *hold = list->next;
	if (list->data != NULL)
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

    costEval(list, NULL, xPos, yPos);
}

// Evaluate cost of a node
int costEval(
    Node *list, 
    Node *newParent,
    int xPos, 
    int yPos 
)
{
    Node *evalNode = findNode(list, xPos, yPos);

    // First check if node is in the list
    if (!evalNode)
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
    int hCost = 14*diag + 10*difX + 10*difY - 20*diag; 
    
    // Later: THE Algorithm goes here
    int fCost = gCost + hCost;
   
    // exit if the old cost is less
    if (newParent && fCost > temp->f)
	return 0;
    else
    {
	// update
	temp->g = gCost;
	temp->h = hCost;
	temp->f = fCost;

	return 0;
    }
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
    for (; list != NULL; list = list->next)
    {
	// if Node is non-empty, we check it out
	if (list->data != NULL)
	{
	    PathNode *temp = (PathNode*)list->data;
	
	    // If it matches, then we're golden
	    if (temp->x == xPos && temp->y == yPos)
		return list;
	}
    }

    // It isn't, so return NULL
    return NULL;
}

// Returns minimum integer
int min(int a, int b)
{
    if (a < b)
	return a;
    else
	return b;
}

// Returns maximum integer
int max(int a, int b)
{
    if (a > b)
	return a;
    else
	return b;
}

// Returns absolute of integer
int abs(int a)
{
    if (a < 0)
	return a*-1;
    else
	return a;
}


