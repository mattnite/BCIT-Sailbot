// A Star pathfinding algorithm class

// Author: Matthew Knight
// File Name: astar.cpp
// Date: 2017-07-23

// This class serves as an interface to different heuristics models for the a
// star pathfinding algorithm.

#include "aStar.hpp"

//ctor
aStar_base::aStar_base(varTable *table, double length)
{

}

// perform the A* algorithm
int aStar_base::run()
{

}

// find lowest cost
std::const_iterator aStar_base::lowCost(std::list<node>& x)
{

}

// Evaluate nodes around node
void aStar_base::eval(node& evalNode)
{

}

// convert gps, create node object
node aStar_base::gps_to_node(std::array<double,2>& gps)
{

}

// convert node to gps
std::array<double,2> aStar_base::node_to_gps(node& gpsNode)
{

}
