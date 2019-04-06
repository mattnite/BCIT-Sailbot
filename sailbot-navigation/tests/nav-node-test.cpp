// NavNode Tests
//
// Author: Matthew Knight
// File Name: nav-node-test.cpp
//
// This file tests:
//		- creation of first 8 children returns valid, unique ptrs, 8th is
//		nullptr

#include "nav-node.hpp"
#include "gtest/gtest.h"

#include <complex>
#include <list>

#define VALID_CHILDREN_NUM 8

TEST(NavNodeTest, ChildrenCreation) {
	std::list<NavNode*> childList;
	std::complex<int> testPos(0,0);
	double testCost = 0;
	NavNode parent(nullptr, testPos, testCost);
	// First 8 children return non-null ptrs
	for (int i = 0; i < VALID_CHILDREN_NUM; i++) {
		NavNode *child = parent.addChild(&parent, testPos, testCost);
		childList.push_front(child);
		ASSERT_NE(child, nullptr);
	}

	// record that the size is 8, remove any duplicates, ensure size of the list
	// doesn't change since there should be no duplicates
	int size = childList.size();
	ASSERT_EQ(size, VALID_CHILDREN_NUM);
	childList.unique();
	ASSERT_EQ(childList.size(), size);
	
	// Adding more children returns nullptr
	NavNode *nullChild = parent.addChild(&parent, testPos, testCost);
	ASSERT_EQ(nullChild, nullptr);
}
