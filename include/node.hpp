// Coordinate node class

// Author: Matthew Knight
// File Name: node.hpp
// Date: 2017-07-08

// This class is used as the building block of the A* pathfinding algorithm

#ifndef NODE_H_
#define NODE_H_

#include <iostream>
#include <array>
#include <vector>
#include "aStar_base.hpp"

class node
{
    friend class aStar_base;
    std::array<int, 2> pos;
    double cost;
    node *parent;

public:
    // ctor
    node(int x, int y);
    
    // add parent via pointer
    int adopt(node *newParent);
};

#endif
