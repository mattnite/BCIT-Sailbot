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

// Defines for node lists
#define END 0
#define PRO 1
#define VIS 2
#define OBS 3
#define PTH 4

typedef struct Node
{
    Node* next;				// Next node in list
    Node* last;				// Last node in A* algorithm
    int x;				// X position of node
    int y;				// Y position of node
    float cost;				// Cost of node
} node;

static int n = 30;			// Length and width of mesh
static Node* mesh[4] = {    NULL, 
			    NULL, 
			    NULL,
			    NULL    };

// Create Node and return pointer
Node* createNode(int xPos, int yPos);

// Function for deallocating memory taken up by the node objects in list
int freeList(Node* list);

// Function to transfer a node from one list to another
int transferNode(Node* transfer, Node* listFrom, Node* listTo);

// Function for adding a node to a list
int addNode(Node** list, int xPos, int yPos);

// Returns magnitude of a vector
float mag(float x, float y);

// Checks cost of a node 
int costCheck(Node* list, int xPos, int yPos, Node* pointTo);

// Tells you if a node exsists within a list
bool findNode(Node* list, int xPos, int yPos);

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
   
    // Look at all the nodes around the beginning, add to prospected list, evaluate cost
    for(int i = mesh[VIS]->x - 1; i < mesh[VIS]->x + 2; i++)
	for(int j = mesh[VIS]->y - 1; j < mesh[VIS]->y + 2; j++)
	    if(!(i == mesh[VIS]->x && j == mesh[VIS]->y))
	    {
		addNode(&mesh[PRO], i, j);
		costCheck(mesh[PRO], i, j, mesh[VIS]);
	    }
    
    // A* Basic algorithm
    // Runs until a node matching the end node is visited
    while(!findNode(mesh[VIS], mesh[END]->x, mesh[END]->y))
    {
	// first we find the lowest cost prospective node
	Node* lowCost = mesh[PRO];
	for(Node* check = mesh[PRO]; check->next != NULL; check = check->next)
	    if(check->cost < lowCost->cost)
		lowCost = check;

	// we then visit that node
	transferNode(lowCost, mesh[PRO], mesh[VIS]);
    
	// visiting that node reqires prospecting all surrounding nodes that havent been visited
	for(int i = lowCost->x - 1; i < lowCost->x + 2; i++)
	{
	    for(int j = lowCost->y - 1; j < lowCost->y + 2; j++)
	    {
		// Make sure the node isnt the current node isn't visited, or an obstacle
		if(!(findNode(mesh[VIS], i, j) || findNode(mesh[OBS], i,j)))
		{
		    if(!findNode(mesh[PRO], i, j))
			addNode(&mesh[PRO], i, j);
		    costCheck(mesh[PRO], i, j, lowCost);
		}
	    }
	}
    }
    
    Node* path = mesh[VIS];
    while(!(path->x == mesh[END]->x && path->y == mesh[END]->y))
	path = path->next;
    
    while(path->last != NULL)
    {
	addNode(&mesh[PTH], path->x, path->y);
	path = path->last;
    }

    // Ncurses demo
    for(int list = 0; list < 5; list ++)
    {
	attron(COLOR_PAIR(list + 1));
	for(Node* check = mesh[list]; check != NULL; check = check->next)
	    if(check->x < n && check->x >= 0 && check->y < n && check->y >= 0)
		mvaddch(n - 1 - check->y, check->x, ' ');
	attroff(COLOR_PAIR(list + 1));
    }
    attron(COLOR_PAIR(endPoint));
    mvaddch(n - 1 - mesh[END]->y, mesh[END]->x, ' ');
    attroff(COLOR_PAIR(endPoint));
    move(n,0);
    refresh();
   
    // deallocate memory of all the nodes
    freeList(mesh[VIS]);
    freeList(mesh[PRO]);
    freeList(mesh[OBS]);
    freeList(mesh[END]);
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
