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

// Function for deallocating memory taken up by the node objects in list
int freeList(Node* list);

// Function to transfer a node from one list to another
int nodeTransfer(Node* transfer, Node* listFrom, Node* listTo);

// Function for adding a node to a list
int nodeAdd(Node* list, int x, int y);

int main()
{
    srand(time(NULL));			// Time seed for random generator
    
    Node* visit = 0;		// initialize visit list
    Node* obst = 0;		// initialize obstacles
    
    initscr();				// Start curses mode
    nodelay(stdscr, false);
    noecho();

    // Generate End coordinates
    int endX = rand() % n;
    int endY = rand() % n;

    // Generate Beginning node, make sure it isn't the end node, add to 
    // prospected 
    Node* prosp = (node*)malloc(sizeof(Node)); 
    prosp->next = 0;
    prosp->last = 0;
    prosp->x = rand() % 20;
    prosp->y = rand() % 20;
    prosp->cost = sqrt((prosp->x - endX)^2 + (prosp->y - endY)^2); // Distance to destination
    
    // Ncurses demo
    printw("Beginning coordinates: %d, %d\n", prosp->x, prosp->y);
    printw("End Coordinates: %d, %d\n", endX, endY);
    printw("Press any key to exit\n");
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
    
    endwin();				// End window

    return 0;
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
int nodeTransfer(
    Node* transfer,			// Node to transfer 
    Node* listFrom,			// Node list to transfer from
    Node* listTo			// Node list to transfer to
)
{

    // Go through first list and find node preceding
    while(*listFrom != transfer)
    {
	listFrom = listfrom->next

    // Go through first list and find node preceding
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
    return 0;
}

