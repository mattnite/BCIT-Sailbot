// Coordinate node class

// Author: Matthew Knight
// File Name: node.hpp
// Date: 2017-07-08

// This class is used as the building block of the A* pathfinding algorithm

#ifndef NODE_H_
#define NODE_H_

#include <tuple>

class node
{
    std::array<int, 2ul> pos;
    std::array<int, 2ul> cost;
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
    void connect(node *newParent);

    // evaluate cost
    void eval(node &end);
};

#endif
