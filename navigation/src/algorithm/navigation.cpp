// Navigation Class Implementation
//
// Author: Matthew Knight
// File Name: navigation.cpp
// Date: 2018-09-08
//
// This class runs a pathfinding algorithm for navigation. It is based off of A
// star, but the cost function is a parameter so that it may be changed to
// account for different variables such as wind.

#include "algorithm/navigation.hpp"

// ctor
Navigation::Navigation(std::complex<int> end, CostFunc costCalc)
	: end(end), costCalc(costCalc), endPoint(nullptr)
{
	tree = new NavNode(nullptr, std::complex<int>(0,0), end);
	unvisited.insert(tree);
}

// get endpoint object
NodeNav *Navigation::getEndPoint() {
	return endPoint;
}

// Change cost function
void Navigation::setCostCalc(CostFunc newCostCalc) {
	costCalc = newCostCalc;
}

// step algorithm forward by one
void Navigation::step() {
	// Pop off the top of the set (lowest cost);
	NavNode *next = *(unvisited.begin());
	unvisited.erase(unvisited.begin());

	// Exit if we found the end point
	if (next->position == end) {
		endPoint = next;
		return;
	}

	// Generate children and add to unvisited set
	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			if (i != 0 && j != 0) {
				std::complex<int> rel(i,j);
				std::complex<int> pos = next->position + rel;
				NavNode *child = next->addChild(
					next,
					pos,
					costCalc(next, pos)
				);

				if (child != nullptr) {
					unvisited.insert(child);
				}
			}
		}
	}
}

// dtor
Navigation::~Navigation() {
	delete tree;
}
