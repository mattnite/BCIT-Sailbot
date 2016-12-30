// Simple Stack Implementation File

// Author: Matthew Knight
// Date: 2016-12-24

// This is a module for a very simple stack for the linked list in the Sailbot

#include "node.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

// Add Node to the top of the stack
int push(Node *stack, Node *element)
{
    // Error if either is NULL
    if(!stack || !element)
	return -1;
    
    Node *top = createNode();
    top->data = element;
    
    // Insert the new node right in there
    Node* hold = stack->next;
    stack->next = top;
    top->next = hold;
}

// Return Node and remove from top of stack
Node *pop(Node *stack)
{
    // Return NULL if any of the below are NULL
    if (!stack)
	return NULL;
    if (!stack->next)
	return NULL;
    if (!stack->next->data)
	return NULL;
    
    Node *top = (Node*)stack->next->data;
    Node *hold = stack->next->next;
    free(stack->next);
    stack->next = hold;
    return top;
}
