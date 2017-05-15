// C++ Pathfinding Algorithm

// Author: Matthew Knight
// Date: 2017-05-14

// This program uses the A* algorithm to optimize the best path from a beggining
// Node to and end node given a list of obstacles.

#include <iostream>
#include <tuple>
#include <list>
#include <algorithm>
#define x 0
#define y 1

using namespace std;

int main (void)
{
    typedef tuple<int, int> node;
    node begin(0, 0), end(5,6);

    list<node> open;
    list<node> closed;
    list<node> obs;
    
    closed.push_back(begin);
    open.push_back(node(3,4));

    // evaluate nodes around
    int xPos = get<x>(closed.back());
    int yPos = get<y>(closed.back());
    
    for (int i = xPos - 1; i < xPos + 2; i++)
    {
	for (int j = yPos - 1; j < yPos + 2; j++)
	{
	    node test(i, j);
	    if (!find(closed, test))
		cout << i << ", " << j << endl;		
	}
    }
		
//			    if (!closed.find(i, j))
//				if(!open.find(i, j))
//				    open.add(i, j, cur);
//				else
//				    open.costEval(i, j, cur);
	
	// transfer open to closed
//	open.transfer(open.cheapest(), closed);
}
/*
    // A* is done when the end point is added to the closed list
    while (!closed.findEnd())
    {
	// The last node added to the closed list
	PathNode *cur = closed.last();



    // Initialize stack and find end node
    Stack path;
    PathNode *endNode = closed.findEnd();

    // pushing to the stack
    for (; endNode->parent; endNode = endNode->parent)
	    path.push(endNode->x, endNode->y);

    // Pop and print
    for(!path.empty())
    {
	cout << path.x() << "," << path.y() << endl;
	path.pop();
    }
}

// Function for converting coordinate string into integer coordinates
int coordToInt(
    char *str,				// Ptr to coordinate str
    int *x,				// Ptr to X int
    int *y				// Ptr to Y int
)
{
    char *yStr;				// Holds Y coord str

    *x = strtol(str, &yStr, 10);
    *y = strtol(yStr + 1, NULL, 10);
}
*/
