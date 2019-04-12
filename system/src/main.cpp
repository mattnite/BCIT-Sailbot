// Sailbot System Program
//
// Author: Matthew Knight
// File Name: main.cpp
// Date: 2019-04-12

#include "bridge.hpp"

#include <iostream>
#include <vector>

/**
 * The first argument is the path to the configuration file.
 */
int main(int argc, char* argv[]) {

	if (argc < 2) {
		std::cout << "Need to provide a path to the config file" << std::endl;
		return 1;
	}

	std::cout << "Config Path: " << argv[1] << std::endl;
}
