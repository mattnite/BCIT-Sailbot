// A Star pathfinding algorithm class

// Author: Matthew Knight
// File Name: astar.hpp
// Date: 2017-07-14

// This class serves as an interface to different heuristics models for the a
// start pathfinding algorithm.

#ifndef ASTAR_BASE_H_
#define ASTAR_BASE_H_

#include <list>
#include <stack>
#include <array>
#include "varTable.hpp"
#include "node.hpp"

class aStar_base
{
    varTable *systemVar;		// pointer to system variables
    double len;				// length of a node in meters
    node endNode; 
    stack<node> path;

public:
    //ctor
    aStar_base(varTable *table, double length);

    // perform the A* algorithm
    int run();

    // find lowest cost
    std::const_iterator lowCost(std::list<node>& x);

    // Evaluate nodes around node
    void eval(node& evalNode);

    // convert gps, create node object
    node gps_to_node(std::array<double,2>& gps);

    // convert node to gps
    std::array<double,2> node_to_gps(node& gpsNode);

private:
    
    // heuristics
    virtual double costEval(node& nut) = 0;
};

#endif
