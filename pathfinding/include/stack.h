// Stack Interface File

// Author: Matthew Knight
// Date: 2016-12-31

// This is a simple implementation of a stack that stores Nodes with an x and
// y coordinate.

#ifndef STACK_H_
#define STACK_H_

class Stack
{
    Node* top;				// Pointer to the top of the stack

public:
    // ctor
    Stack();

    // push onto the stack
    void push(int x, int y);

    // check x coordinate
    int x();
    
    // check y coordinate
    int y();

    // pop off the stack
    void pop();

    // check if it's empty
    int empty();

    // dtor
    ~Stack();
};

#endif
