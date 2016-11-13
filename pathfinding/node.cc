// Node Implemetation File

// Author: Matthew Knight
// Date: 2016-11-12

// This file contains functions used for the A* Algorithm using linked lists

// Gives the magnitude of a vector
float mag(float x, float y);

// Create Node and return pointer
Node* createNode(
    int xPos,				// X position of node
    int yPos				// Y position of node
)
{
    // Allocate memory and then set up node
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->x = xPos;
    temp->y = yPos;
    temp->next = NULL;
    temp->last = NULL;
    temp->cost = 0;
    return temp;
}

// Function for deallocating memory taken up by the node objects in list
int freeList(
    Node* list				// List of nodes to deallocate
)
{
    while(list != NULL)
    {
	Node* hold = list->next;
	free(list);
	list = hold;
    }

    return 0;
}

// Function to transfer a node from one list to another
int transferNode(
    Node* transfer,			// Node to transfer 
    Node* listFrom,			// Node list to transfer from
    Node* listTo			// Node list to transfer to
)
{
    // Exit if empty list
    if(listFrom == NULL)
	return -1;

    // Go through first list and find node preceding
    while(listFrom->next != transfer)
    {
	// Exit if list doesn't contain the transfer node, otherwise
	// move pointer up the list
	if(listFrom->next == NULL)
	    return -2;
	
	listFrom = listFrom->next;
    }
    
    // The node preceding points to node after transfer reset transfer ptr
    listFrom->next = transfer->next;
    transfer->next = NULL;

    // If second list is empty
    if(listTo == NULL)
	listTo = transfer;
    else
    {
	// Find end of second list, insert transfer at end
	while(listTo->next != NULL)
	    listTo = listTo->next;
	listTo->next = transfer;
    }
    return 0;
}

// Function for adding a node to a list
int addNode(
    Node** list,
    int xPos,				// X coordinate
    int yPos				// Y coordinate
)
{
    Node* check = *list;
    if(*list == NULL)
	*list = createNode(xPos ,yPos);
    else
    {
	// Loop through and find the end of the list
	for(; check->next != NULL; check = check->next)
	    ;    
	// Make list point to the new Node
	check->next = createNode(xPos, yPos);
    }
    return 0;
}

// Calculate magnitude of a vector
float mag(
    float x, 
    float y
)
{
    return sqrt(x*x + y*y);
}

int costCheck(Node* list, int xPos, int yPos, Node* pointTo)
{
    // Loop through list and find node
    for(; !(list->x == xPos && list->y == yPos); list = list->next)
	if(list == NULL)
	    return -1;

    // Point the last pointer to the current visited node   
    list->last = pointTo;

    // Cost evaluation
    list->cost = mag(list->x - mesh[VIS]->x, list->y - mesh[VIS]->y) 
	+ mag(list->x - mesh[END]->x, list->y - mesh[END]->y);
}

// Find out if a node exists within a list
bool findNode(
    Node* list, 
    int xPos, 
    int yPos
)
{
    // If list is empty
    if(list == NULL)
	return false;
    
    // If the node is in the list, return true
    for(; list != NULL; list = list->next)
	if(list->x == xPos && list->y == yPos)
	    return true;

    // It isn't, so return false
    return false;
}
