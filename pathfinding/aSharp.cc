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

static int n = 20;			// Length and width of mesh

typedef struct Node
{
    node* next;				// Next node in list
    node* last;				// Last node in A* algorithm
    int x;				// X position of node
    int y;				// Y position of node
    int cost;				// Cost of node
} node;

// Function for deallocating memory taken up by the node objects in list
int freeList(node* list)
{
    while(list != NULL)
    {
	next = list*;
	free(list);
	list = next;
    }

    return 0;
}

int main()
{
    srand(time(NULL));			// Time seed for random generator
    
    node* prospected = 0;		// initialize prospected list
    nose* obstacles = 0;		// initialize obstacles
    
    initscr();				// Start curses mode


    // Generate End coordinates
    endX = rand() % n;
    endY = rand() % n;

    // Generate Beginning node, make sure it isn't the end node
    node* visited = (node*)malloc(sizeof(Node)); 
    
    // Add Beginning node to the prospected list
	/* Begin pathfinding algorithm:
	    1. 
	    2. 
	    3. 
	    4.  
	*/
    
    // deallocate memory of all the nodes
    freeList(visited);
    freeList(prospected);
    freeList(obstacles);
    
    endwin();				// End window

    return 0;
}
