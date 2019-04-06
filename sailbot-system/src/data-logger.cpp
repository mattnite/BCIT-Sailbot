// Data Logger Process
//
// Author: Matthew Knight
// File Name: data-logger.cpp
// Date: 2018-10-14
//
// This process periodically samples the system table and calls it's print
// method and outputs to stdout periodically. The output format is csv.

#include "system-table.hpp"

#include <chrono>
#include <iostream>
#include <thread>

// TODO: add command line arguments to make it more configurable

int main() {
	SystemTable table("./shared_mem");

	// loop forever
	while (true) {
		Table t = table.getTable();
		std::cout << t << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}
