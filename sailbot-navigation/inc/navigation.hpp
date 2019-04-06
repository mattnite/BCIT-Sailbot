// Navigation Class Interface
//
// Author: Matthew Knight
// File Name: navigation.hpp
// Date: 2018-09-08
//
// This class runs a pathfinding algorithm for navigation. It is based off of A
// star, but the cost function is a parameter so that it may be changed to
// account for different variables such as wind.

#ifndef SAILBOT_NAVIGATION_HPP_
#define SAILBOT_NAVIGATION_HPP_

#include "nav-node.hpp"

#include <complex>
#include <functional>
#include <set>

// Function object to compare NavNodes
struct compNavNode {
	bool operator()(NavNode *lhs, NavNode *rhs) {
		return lhs->cost < rhs->cost;
	}
};

// type definition for cost function
typedef std::function<double (
	NavNode*, 
	std::complex<int>&, 
	std::complex<int>&
)> CostFunc;

class Navigation {
	std::complex<int> end;
	// Holds actual enpoint object
	NavNode *endPoint;
	NavNode *tree;
	std::set<NavNode*,compNavNode> unvisited;
	CostFunc costCalc;

public:
	// ctor
	Navigation(std::complex<int> end, CostFunc costCalc);
	
	// Get endpoint object
	NavNode *getEndPoint();

	// Change cost function
	void setCostCalc(CostFunc newCostCalc);

	// step algorithm forward by one
	void step();			

	// dtor
	~Navigation();
};


#endif
