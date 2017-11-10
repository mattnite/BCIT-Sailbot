// A-star pathfinding class interface

// Author: Matthew Knight
// File Name: aStar.hpp
// Date: 2017-08-07

#ifndef ASTAR_H_
#define ASTAR_H_

#include <list>
#include <stack>
#include <array>
#include <cmath>

// For printing coordinates
std::ostream& operator<<(std::ostream& os, std::array<int,2>& pair);

class node
{
    friend class aStar;
    std::array<int, 2> pos;
    double cost;
    node *parent;

public:
    // default ctor
    node() : cost(INFINITY), parent(NULL)
    {}
    
    // ctor
    node(int x, int y) : pos({x, y}), cost(INFINITY), parent(NULL)
    {}

    std::array<int,2> &position()
    {
	return pos;
    }
};

class aStar
{
    node end;
    std::list<node> objects;
    std::list<node> open;
    std::list<node> closed;
    std::stack<node> path;

public:
    // default ctor
    aStar();

    // end node ctor
    aStar(node &End);

    // full ctor
    aStar(node &End, std::list<node> &Obj);

    // set end node
    int setEnd(int x, int y);

    // set object list
    int setObj(std::list<node> &Obj);

    // add object
    int addObj(int x, int y);

    // run the algorithm
    int run();

    // return calculated path
    std::stack<node> &getPath();

private:
    // helper functions
    bool inList(node &nd, std::list<node> &lst);

    // Evaluate node
    int evalNode(node &nd);

    // Find lowest cost node in list
    std::list<node>::iterator lowCost(std::list<node> &lst);

    // return cost of node with parent
    virtual double nodeCost(node &child, node &parent);

};

#endif
