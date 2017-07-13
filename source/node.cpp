// Coordinate node class

// Author: Matthew Knight
// File Name: node.cpp
// Date: 2017-07-08

#include "node.hpp"

// ctor 1
node::node(int x, int y)
:pos(x,y)
{}

// return x position
int node::x()
{
    return std::get<0>(pos);
}

// return y position
int node::y()
{
    return std::get<1>(pos);
}

// connect
void node::connect(node *newParent)
{
    parent = newParent;
    parent->children.push_pack(this);
}

// evaluate cost
void node::eval(node &end)
{

}
