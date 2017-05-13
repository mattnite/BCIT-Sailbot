// Queue Implementation File

// Author: Matthew Knight
// Date: 2016-12-31

// The queue is for storing the list of nodes for the path

#include "stdlib.h"
#include "../include/queue.h"
#include <iostream>

// ctor
Queue::Queue()
:top(NULL)
{}

// add Node to queue
void Queue::add(int xPos, int yPos)
{
    // if the queue is empty
    if (empty())
    {
	top = new Node(xPos, yPos);
    }
    else
    {
	Node *parse = top;

	for (; parse->next != NULL; parse = parse->next)
	    ;
	parse->next = new Node(xPos, yPos);
    }
}

// return x coordinate of top node
int Queue::getX()
{
    if (empty())
    {
	std::cerr << "The Queue is empty" << std::endl;
	return 0;
    }
    else
	return top->x;
}

// return y coordinate of top node
int Queue::getY()
{
    if (empty())
    {
	std::cerr << "The Queue is empty" << std::endl;
	return 0;
    }
    else
	return top->y;
}

// delete top node and move to teh next one
void Queue::next()
{
    if (empty())
	return ;
    Node *hold= top->next;
    delete top;
    top = hold;
}

// check to see if queue is empty
int Queue::empty()
{
    if (top)
	return 0;
    else
	return 1;
}

//dtor
Queue::~Queue()
{
    Node *parse = top;
    while (parse != NULL)
    {
	Node* hold = parse->next;
	delete parse;
	parse = hold;
    }
}
