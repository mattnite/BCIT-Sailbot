// Navigation Node
//
// Author: Matthew Knight
// File Name: nav-node.hpp
// Date: 2018-09-07
//
// This class represents a node within the navigation tree. It has a pointer to
// it's parent so that the cost calculation can use past history of the route,
// and 8 pointers to children which represent 8 different directions it can go.

#ifndef SAILBOT_NAV_NODE_HPP_
#define SAILBOT_NAV_NODE_HPP_

#include <array>
#include <complex>
#include <functional>

class NavNode {
	std::complex<int> position;
	NavNode *parent;
	std::array<NavNode*, 8> children;
	int childCount;
	double cost;
	double acc;

public:
	// ctor
	NavNode(NavNode *parent, std::complex<int> &position,  double cost);
	
	// Add child to array
	NavNode *addChild(NavNode *parent, std::complex<int> &position, double cost);

	// handle deletion of children
	~NavNode();
};

#endif
