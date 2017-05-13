// Path Linked List Implementation File

// Author: Matthew Knight
// Date: 2016-12-31

// The PathList is a linked list tailored for A* pathfinding. Since it is
// intended that different heuristic methods be tested, another base class
// algorithm will be defined in order to generalize the process.


#include <stdlib.h>
#include "../include/cpp/node.h"
#include "../include/pathList.h"

/* Linked List Methods */

// ctor
LinkedList::LinkedList()
:first(NULL)
{}
    
// add node to list
int LinkedList::add(int xPos, int yPos)
{
    // Find end of list
    Node* parse = first;
    for(; parse != NULL; parse = parse->next)
	;
    // Create new Node at end of list
    parse->next = new Node(xPos, yPos);
}

// Find a node and return a pointer to it
Node *LinkedList::find(int xPos, int yPos)
{
    // Find node that matches, return NULL if it doesn't exist
    Node *parse = first;
    for (; !(parse->x == xPos && parse->y == yPos); parse = parse->next)
    {
	if (parse == NULL)
	    return NULL;
    }
    
    // found it
    return parse;
}

// find last node in list
Node *LinkedList::last()
{
    Node *parse = first;
    for (; parse->next != NULL; parse = parse->next)
	;
    return parse;
}

// dtor
LinkedList::~LinkedList()
{
    // Go through list and delete all the nodes
    Node *parse = first;
    while (parse != NULL)
    {
	Node *hold = parse->next;
	delete parse;
	parse = hold;
    }
}

/* PathList Methods */

// ctor
PathList::PathList(int ex = 0, int ey = 0, float wd = 0, float ws = 0, 
    float ih = 0, float iv = 0)
:LinkedList(), windDir(wd), windSpd(ws), initHeading(ih), initVel(iv), endX(ex), 
    endY(ey)
{}
    
// Add PathNode
int PathList::add(int xPos, int yPos, PathNode* parent = NULL)
{
    // Find end of list
    Node* parse = first;
    for(; parse != NULL; parse = parse->next)
	;
    // Create new Node at end of list
    parse->next = new PathNode(xPos, yPos, parent); 
}

// Transfer Node to a different List
int PathList::transfer(PathNode *send, PathList &dest)
{
    // Find end of destination Pathlist and point it at transfered Node
    Node *parse = dest.first;
    for (; parse->next != NULL; parse = parse->next)
	;
    parse->next = send;
    
    // Remove ties to sent Node
    Node *hold = this->find(send->x, send->y)->next;
    parse = this->first;
    for (; parse->next != send; parse = parse->next)
	;
    parse->next = hold;
    send->next = NULL;
}

// Evaluate Cost of a Node
int PathList::costEval(int xPos, int yPos, PathNode *parent)
{
    
}

// Return pointer to cheapest node in list
PathNode *PathList::cheapest()
{

}

// Determine if end node is in list
Node *findEnd()
{
    return this->find(endX, endY);
}

// dtor
PathList::~PathList()
{
    // Go through list and delete all the nodes
    PathNode *parse = this->first;
    while (parse != NULL)
    {
	PathNode *hold = parse->next;
	delete parse;
	parse = hold;
    }
}

