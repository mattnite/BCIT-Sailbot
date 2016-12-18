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
#include <unistd.h>
#include "node.h"			// Linked lists for A*

static int n = 30;			// Length and width of mesh

// print lists
int printLists(void);


int main()
{
    srand(time(NULL));			// Time seed for random generator
    
    initscr();				// Start curses mode
    nodelay(stdscr, false);
    noecho();
    scrollok(stdscr, true);
    start_color();
    
    // Color modes
    enum colorPair
    {
	endPoint = 1,
	prospected,
	visited,
	obstacles,
	pathTaken
    };

    // Initialize color pairs
    init_pair(endPoint, COLOR_BLACK, COLOR_YELLOW);
    init_pair(visited, COLOR_BLACK, COLOR_RED);
    init_pair(prospected, COLOR_BLACK, COLOR_GREEN);
    init_pair(obstacles, COLOR_BLACK, COLOR_WHITE);
    init_pair(pathTaken, COLOR_BLACK, COLOR_CYAN);
   
    // Generate End Node (can be seen as a list of one node)
    addNode(&mesh[END], rand() % n, rand() % n);

    // Generate Beginning node, make sure it isn't the end node, add to 
    // visited
    addNode(&mesh[VIS], rand() % n, rand() % n);

    for (int i = 0; i < n/2; i++)
	addNode(&mesh[OBS], i + 5, 10);
    // Look at all the nodes around the beginning, add to prospected list, evaluate cost
    for(int i = mesh[VIS]->x - 1; i < mesh[VIS]->x + 2; i++)
    {
	for(int j = mesh[VIS]->y - 1; j < mesh[VIS]->y + 2; j++)
	{	    
	    if(!(i == mesh[VIS]->x && j == mesh[VIS]->y))
	    {
		addNode(&mesh[PRO], i, j);
		costCheck(mesh[PRO], i, j, mesh[VIS]);
	    }
	}
    }

    // A* Basic algorithm
    // Runs until a node matching the end node is visited
    while(!findNode(mesh[VIS], mesh[END]->x, mesh[END]->y))
    {
	printLists();
	usleep(100000);
	// first we find the lowest cost prospective node
	Node* lowCost = mesh[PRO];
	for(Node* check = mesh[PRO]; check->next != NULL; check = check->next)
	    if(check->cost < lowCost->cost)
		lowCost = check;

	// We visit it by transfering it to the visited list
	transferNode(lowCost, mesh[PRO], mesh[VIS]);
    
	// Prospecting surrounding nodes that are not visited or obstacles
	for(int i = lowCost->x - 1; i < lowCost->x + 2; i++)
	{
	    for(int j = lowCost->y - 1; j < lowCost->y + 2; j++)
	    {
		// Make sure the node isnt the current node isn't visited, or an obstacle
		if(!(findNode(mesh[VIS], i, j) || findNode(mesh[OBS], i,j)))
		{
		    // If node doesn't exist, make it
		    if(!findNode(mesh[PRO], i, j))
			addNode(&mesh[PRO], i, j);
		    // Make the node point to the current visited node
		    costCheck(mesh[PRO], i, j, lowCost);
		}
	    }
	}
    }
    
    // Find end of determined path so that we can retrace steps of determined
    // path
    Node* path = mesh[VIS];
    while(!(path->x == mesh[END]->x && path->y == mesh[END]->y))
	path = path->next;
    
    // Create list of nodes that are the determined path
    while(path->last != NULL)
    {
	addNode(&mesh[PTH], path->x, path->y);
	path = path->last;
    }

    printLists();

   
    // deallocate memory of all the nodes
    freeList(mesh[VIS]);
    freeList(mesh[PRO]);
    freeList(mesh[OBS]);
    freeList(mesh[END]);
    
    // Exiting Program
    mvprintw(n, 0, "Press any key to exit\n");
    refresh();
    getch();
    endwin();				// End window

    return 0;
}

// Print all nodes in their respective colors
int printLists(void)
{
    for(int list = 0; list < 5; list ++)
    {
	attron(COLOR_PAIR(list + 1));
	for(Node* check = mesh[list]; check != NULL; check = check->next)
	    if(check->x < n && check->x >= 0 && check->y < n && check->y >= 0)
		mvaddch(n - 1 - check->y, check->x, ' ');
	attroff(COLOR_PAIR(list + 1));
    }
    
    // Reprint the end point
    attron(COLOR_PAIR(1));
    mvaddch(n - 1 - mesh[END]->y, mesh[END]->x, ' ');
    attroff(COLOR_PAIR(1));
    
    refresh();
    return 0;
}   

