// Queue Interface File

// Author: Matthew Knight
// Date: 2016-12-29

#ifndef QUEUE_H_
#define QUEUE_H_

#include "node.h"

// Add node to the queue
void addToQueue(Node *q, int xPos, int yPos);

// get the x coord of the next node
int getNextX(Node *q);

// get the y coord of the next node
int getNextY(Node *q);

// advance the queue
int advanceQ(Node *q);


#endif
