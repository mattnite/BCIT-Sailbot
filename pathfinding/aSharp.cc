// Flavourless A* Alogrithm 

// Author: Matthew Knight
// Date: 2016-11-06

// This program demonstrates the A* pathfinding algorithm on a 20x20 mesh.
// There is no weighting, the mesh will "play" and will show the steps of how
// the algroithm found the destination. Start, destination, and obstacles will
// be randomly generated.

#include <ncurses.h>
#include "meshNode.h"

typedef struct Node
{
    Node* next;
    Node* last;
    int x;
    int y;
    int cost;
}

static int n = 20;			// Length and width of mesh

int main()
{
    initscr();				// Start curses mode
    
    // Generate End node

    // Generate Beginning node, make sure it isn't the end node
    
    endwin();				// End window

    return 0;
}
