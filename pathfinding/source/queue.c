// Queue Implementation File

// Author: Matthew Knight
// Date: 2016-12-29


#include "queue.h"
#include "node.h"
#include <stdlib.h>

// Add node to the queue
void addToQueue(Node *q, int xPos, int yPos)
{
    addNode(q, NULL, xPos, yPos);
}

// get the x coord of the next node
int getNextX(Node *q)
{
    PathNode *check = (PathNode*)q->data;
    return check->x;
}

// get the y coord of the next node
int getNextY(Node *q)
{
    PathNode *check = (PathNode*)q->data;
    return check->y; 
}

// advance the queue
int advanceQ(Node *q)
{
    Node *holder = q->next->next;
    free(q->data);
    free(q->next);
    q->next = holder;
}


