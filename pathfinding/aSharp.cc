// Flavourless A* Alogrithm 

// Author: Matthew Knight
// Date: 2016-11-06

// This program demonstrates the A* pathfinding algorithm on a 20x20 mesh.
// There is no weighting, the mesh will "play" and will show the steps of how
// the algroithm found the destination. Start, destination, and obstacles will
// be randomly generated.

#include <ncurses.h>			// For the ncurses environment
#include <time.h>
#include <stdlib.h>			// rand()
#include <math.h>			// sqrt()

static int n = 20;			// Length and width of mesh
typedef struct Node
{
    Node* next;				// Next node in list
    Node* last;				// Last node in A* algorithm
    int x;				// X position of node
    int y;				// Y position of node
    float cost;				// Cost of node
} node;

// Create Node and return pointer
Node* createNode(int xPos, int yPos);

// Analyzes cost of node
int costCheck(Node* check, Node* end);

// Function for deallocating memory taken up by the node objects in list
int freeList(Node* list);

// Function to transfer a node from one list to another
int nodeTransfer(Node* transfer, Node* listFrom, Node* listTo);

// Function for adding a node to a list
int nodeAdd(Node* list, int x, int y);

int main()
{
    srand(time(NULL));			// Time seed for random generator
    
    Node* visit = NULL;		// initialize visit list
    Node* obst = NULL;		// initialize obstacles
    Node* prosp = NULL;		// initialize prospeted node list
    
    initscr();				// Start curses mode
    nodelay(stdscr, false);
    noecho();

    // Generate End Node (can be seen as a list of one node)
    Node* end = createNode(rand() % n, rand() % n);

    // Generate Beginning node, make sure it isn't the end node, add to 
    // prospected 
    Node* prosp = (node*)malloc(sizeof(Node)); 
    prosp->next = 0;
    prosp->last = 0;
    prosp->x = rand() % 20;
    prosp->y = rand() % 20;
    prosp->cost = 1.2; // Distance to destination
    
    // Ncurses demo
    printw("Beginning coordinates: %d, %d\n", prosp->x, prosp->y);
    printw("End Coordinates: %d, %d\n", endX, endY);
    printw("Distance to travel: %f\n", prosp->cost);
    printw("Press any key to delete Nodes\n");
    refresh();
    getch();
    



    // Add Beginning node to the prospected list
	/* Begin pathfinding algorithm:
	    1. 
	    2. 
	    3. 
	    4.  
	*/
    
    // deallocate memory of all the nodes
    freeList(visit);
    freeList(prosp);
    freeList(obst);
    printw("Press any key to exit\n");
    refresh();
    getch();
    endwin();				// End window

    return 0;
}

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

// Analyze cost of node
int costCheck(Node* check, Node* end)
{
    check->cost = sqrt(check->x - end->x + check->y - end->y);
    return 0;
}
// Function for deallocating memory taken up by the node objects in list
int freeList(
    Node* list				// List of nodes to deallocate
)
{
    while(list != NULL)
    {
	printw("Deleting Node at %d, %d\n", list->x, list->y);
	Node* hold = list->next;
	free(list);
	list = hold;
    }

    return 0;
}

// Function to transfer a node from one list to another
int nodeTransfer(
    Node* transfer,			// Node to transfer 
    Node* listFrom,			// Node list to transfer from
    Node* listTo			// Node list to transfer to
)
{
    Node* before = 0;			// A holder variable
    
    // Go through first list and find node preceding
    while(true)
    {
	// Exit if list doesn't contain the transfer node
	if(listFrom == NULL)
	    return -1;	
    }
    // save pointer to the node after transfer
    // zero out transfer node next
    // point previous node of transfer to node after transfer
    // go through second list, make it point to transfer
    
    
    return 0;
}

// Function for adding a node to a list
int nodeAdd(
    Node* list,				// List to add to
    int x,				// X coordinate
    int y				// Y coordinate
)
{
    Node* temp = createNode(x,y);
    
    // Loop through and find the end of the list
    // Make list point to the new Node
    
    return 0;
}

