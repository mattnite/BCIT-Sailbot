// Queue Interface File

// Author: Matthew Knight
// Date: 2016-12-31

// The queue is for storing the list of nodes for the path

#ifndef QUEUE_H_
#define QUEUE_H_

#include "./cpp/node.h"

class Queue
{
    Node *top;				// Pointer to the top node

public:
    // ctor
    Queue();

    // add Node to queue
    void add(int xPos, int yPos);

    // return x coordinate of top node
    int getX();

    // return y coordinate of top node
    int getY();

    // delete top node and move to teh next one
    void next();

    // check if the queue is empty
    int empty();

    //dtor
    ~Queue();
    
};

#endif
