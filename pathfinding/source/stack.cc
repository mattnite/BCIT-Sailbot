// Stack Implementation File

// Author: Matthew Knight
// Date: 2017-01-08

// This is a simple implementation of a stack that stores Nodes with an x and
// y coordinate.

#include "../include/stack.h"
#include "../include/cpp/node.h"

/* Stack Methods */

// ctor
Stack::Stack()
:top(NULL)
{}

// push onto the stack
void Stack::push(int x, int y)
{
    // Hold current top node, make new node, and put it on top
    Node* hold = top;
    top = new Node(x, y);
    top->next = hold;
}

// return x coordinate
int Stack::x()
{
   return top->x; 
}

// return y coordinate
int Stack::y()
{
    return top->y;
}

// pop off the stack
void Stack::pop()
{
    // if there is something there, delete it
    if (top)
    {
	Node *hold = top->next;
	delete top;
	top = hold;
    }
}

// check if it's empty
int Stack::empty()
{
    if (top)
	return 0;
    else
	return 1;
}

// dtor
Stack::~Stack()
{}
