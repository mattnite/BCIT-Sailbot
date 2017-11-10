// A-star pathfinding class implementation

// Author: Matthew Knight
// File Name: aStar.cpp
// Date: 2017-08-07

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include "aStar.hpp"

// Overload for printing position
std::ostream& operator<<(std::ostream& os, std::array<int,2>& pair)
{
    os << pair[0] << "," << pair[1];
}

// default ctor
aStar::aStar()
{
    node begin(0, 0);
    begin.cost = 0;
    closed.push_back(begin);
}


// end node ctor
aStar::aStar(node &End)
    : end(End)
{
    node begin(0, 0);
    begin.cost = 0;
    closed.push_back(begin);
}

// full ctor
aStar::aStar(node &End, std::list<node> &Obj)
    : end(End)
    , objects(Obj)
{
    node begin(0, 0);
    closed.push_back(begin);
    
    run();
}

// set end node
int aStar::setEnd(int x, int y)
{
    end = node(x, y);
    return 0;
}

// set object list
int aStar::setObj(std::list<node> &Obj)
{
    objects = Obj;
    return 0;
}

// add object
int aStar::addObj(int x, int y)
{
    objects.push_back(node(x, y));
    return 0;
}

// run the algorithm
int aStar::run()
{
    // while end node is not in closed list
    while (!inList(end, closed))
    {
	// Hard limit to avoid misuse
	if (closed.size() > 1000)
	{
	    std::cerr << "Path length is too long" << std::endl;
	    break;
	}

	// Evaluate nodes around last added closed node. Find lowwest cost in
	// the open list and add to closed.

	if (evalNode(closed.back()))
	    return -1;

	std::list<node>::iterator it = lowCost(open);
	closed.splice(closed.end(), open, it);
    }

    // Push path onto stack
    for (node *ndPtr = &closed.back(); ndPtr != NULL; ndPtr = ndPtr->parent)
	path.push(*ndPtr);
    
    return 0;
    
}

// return calculated path
std::stack<node> &aStar::getPath()
{
    return path;
}

// check if node is in list
bool aStar::inList(node &nd, std::list<node> &lst)
{
    for (std::list<node>::iterator it = lst.begin(); it != lst.end(); it++)
	if ((*it).pos == nd.pos)
	    return true;

    return false;
}

// Evaluate node
int aStar::evalNode(node &nd)
{
    int x = nd.pos[0];
    int y = nd.pos[1];

    for (int i = x-1; i < x+2; i++)
    {
	for (int j = y-1; j < y+2; j++)
	{
	    node test(i,j);
	    
	    // Make sure it's not in the closed list
	    if (inList(test, closed))
		continue;
		
	    // Make sure it's not in the objects list
	    if (inList(test, objects))
		continue;
	    
	    // No cutting corners
	    if (i != x && j != y)
	    {
		node n1(x, j), n2(i, y);
		if (inList(n1, objects) || inList(n2, objects))
		    continue;
	    }

	    // Check if it already is on the open list
	    if (inList(test, open))
	    {
		// find it
		std::list<node>::iterator it = open.begin();
		while ((*it).pos != test.pos)
		    it++;

		if ((*it).parent != &nd)
		{
		    double testCost = nodeCost(*it, nd);
		    if (testCost < (*it).cost)
		    {
			(*it).parent = &nd;
			(*it).cost = testCost;
		    }
		}
	    }
	    // It's a brand new node
	    else
	    {
		// Update some values
		test.cost = nodeCost(test, nd);
		test.parent = &nd;

		// add to the open list
		open.push_back(test);
	    }
	}
    }
    
    // check if there are any open nodes left
    if (open.size() == 0)
    {
	std::cerr << "Can't find a path" << std::endl;
	return -1;
    }

    return 0;
}

// Find lowest cost node in list
std::list<node>::iterator aStar::lowCost(std::list<node> &lst)
{
    std::list<node>::iterator low = lst.begin();
    for (std::list<node>::iterator it = lst.begin(); it != lst.end(); it++)
    {
	if ((*it).cost < (*low).cost)
	    low = it;
    }
    
    return low;
}

// return cost of node with parent
double aStar::nodeCost(node &child, node &parent)
{
    double c;
    
    // G cost
    if ((child.pos[0] != parent.pos[0]) && (child.pos[1] != parent.pos[1]))
	c = 14;
    else
	c = 10;
 
    // H cost
    int xDiff = abs(end.pos[0] - child.pos[0]);
    int yDiff = abs(end.pos[1] - child.pos[1]);

    c += std::min(xDiff, yDiff)*14;
    c += abs(xDiff - yDiff)*10;

    return c;
}
