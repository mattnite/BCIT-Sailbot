// Navigation Node
//
// Author: Matthew Knight
// File Name: nav-node.cpp
// Date: 2018-09-07
//
// This class represents a node within the navigation tree. It has a pointer to
// it's parent so that the cost calculation can use past history of the route,
// and 8 pointers to children which represent 8 different directions it can go.

#include "algorithm/nav-node.hpp"

// ctor
NavNode::NavNode(NavNode *parent, std::complex<int> &position, double cost) 
	: position(position), parent(parent), cost(cost), acc(0), childCount(0) {
	for (int i = 0; i < children.size(); i++) {
		children[i] = nullptr;
	}
}

// add child to array
NavNode *NavNode::addChild(
	NavNode *parent, 
	std::complex<int> &position,
	double cost
) {
	if (childCount < 8) {
		NavNode *newChild = new NavNode(parent, position, cost);
		children[childCount++] = newChild;
		return newChild;
	} else {
		return nullptr;
	}
}

// Destructor releases children
NavNode::~NavNode() {
	for (int i = 0; i < children.size(); i++) {
		if (children[i] != nullptr) {
			delete children[i];
		}
	}
}

const double& NavNode::getCost() {
	return cost;
}
