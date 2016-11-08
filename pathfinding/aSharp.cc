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

typedef struct Node
{
    Node* next;				// Next node in list
    Node* last;				// Last node in A* algorithm
    int x;				// X position of node
    int y;				// Y position of node
    float cost;				// Cost of node
} node;

static int n = 20;			// Length and width of mesh
static Node* mesh[4];

// Create Node and return pointer
Node* createNode(int xPos, int yPos);

// Analyzes cost of node
int costCheck(Node* check, Node* begin, Node* end);

// Function for deallocating memory taken up by the node objects in list
int freeList(Node* list);

// Function to transfer a node from one list to another
int transferNode(Node* transfer, Node* listFrom, Node* listTo);

// Function for adding a node to a list
int addNode(Node* list, int x, int y);

// Returns magnitude of a vector
float mag(float x, float y);

int main()
{
    srand(time(NULL));			// Time seed for random generator
    
    initscr();				// Start curses mode
    nodelay(stdscr, false);
    noecho();

    // Generate End Node (can be seen as a list of one node)
    mesh[END] = createNode(rand() % n, rand() % n);

    // Generate Beginning node, make sure it isn't the end node, add to 
    // prospected 
    mesh[PRO] = createNode(rand() % n, rand() % n);
    costCheck(mesh[PRO], mesh[PRO], mesh[END]);

    // add some node
    addNode(mesh[PRO], 3, 4);
    addNode(mesh[PRO], 15, 15);

    // A* Basic algorithm
    // first we find the lowest cost prospective node
    Node* lowCost = mesh[PRO];
    Node* checker = mesh[PRO];

    while(checker->next != NULL)
    {
	if(checker->cost < lowCost->cost)
	    lowCost = checker;
	checker = checker->next;
    }

    printw("The lowest cost node is %d, %d with cost of %f\n", lowCost->x, lowCost->y, lowCost->cost);
    
    // we then visit that node
    //transferNode(lowCost, prosp, visit);
	// visiting that node reqires prospecting all surrounding nodes that havent been visited
	// check to see if a
	// if a node has been prospected, the "last" pointer is then

    
    // Ncurses demo
    printw("Beginning coordinates: %d, %d\n", mesh[PRO]->x, mesh[PRO]->y);
    printw("End Coordinates: %d, %d\n", mesh[END]->x, mesh[END]->y);
    printw("Cost of beginning node: %f\n", mesh[PRO]->cost);
    printw("Press any key to delete Nodes\n");
    refresh();
    getch();
   
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

// Analyze cost of node
int costCheck(Node* check, Node* begin, Node* end)
{
    check->cost = mag(check->x - begin->x, check->y - begin->y)
	+ mag(check->x - end->x, check->y - end->y);
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
    Node* list,				// List to add to
    int x,				// X coordinate
    int y				// Y coordinate
)
{
    if(list == NULL)
	list = createNode(x,y);
    else
    {
	// Loop through and find the end of the list
	while(list->next != NULL)
	    list = list->next;
    
	// Make list point to the new Node
	list->next = createNode(x,y);
    }
    return 0;
}

// Calculate magnitude of a vector
float mag(float x, float y)
{
    return sqrt(x*x + y*y);
}
