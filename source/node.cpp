// Coordinate node class

// Author: Matthew Knight
// File Name: node.cpp
// Date: 2017-07-08

#include "node.hpp"

// ctor 1
node::node(int x, int y)
    : pos[0](x)
    , pos[1](y)
    , parent(NULL)
{}

// Add parent via pointer
int node::adopt(node *newParent)
{
    parent = newPointer;
}
