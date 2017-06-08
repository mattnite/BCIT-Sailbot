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
/*
// Simple list search
bool isin(std::list<node> elemList, node elem);

class node
{
    std::tuple <int, int> pos;
    std::tuple <int, int> cost;
    node *parent;
    std::vector<node*> children;
public:
    // ctor 1
    node(int x, int y);
    
    // return x position
    int x();

    // return y position
    int y();

    // connect
    void connect(node *parent)

    // evaluate cost
    void eval(&node end);

    // overload == operator
}


int main (void)
{
    node begin(0, 0), end(5,6);

    std::list<node> open;
    std::list<node> closed;
    std::list<node> obs;
    
    closed.push_back(begin);
    
    // evaluate nodes around
    int xPos = closed.back().x();
    int yPos = closed.back().y();
    while true: // Need exit clause like a timeout 
    {
	for (int i = xPos - 1; i < xPos + 2; i++)
	{
	    for (int j = yPos - 1; j < yPos + 2; j++)
	    {
		node test(i, j);
		// make sure it isnt already visited or an obstacle
		if (!find(closed, test))
		{
		    // if not open already, then add
		    if (!isin(open, test)
			open.push_back(test)
		    // set iterator to test
			
		    // now connect and evaluate
		    it->connect(closed.back);
		    it->eval(end);

		    // find lowest cost in open list
			// if it is end node, return path

			// else add to closed
		}
	    }
	}
    }
}		

// Simple list search
bool isin(std::list<node> elemList, node elem)
{
    // Loop through list
    for (std::list<node>::iterator it = elemList.begin(); 
        it != elemList.end(); ++it)
    {
	if (*it == elem)
	    return true;
    }

    return false;
}
*/
