// main tester
//

#include "system-table.hpp"
#include "table.hpp"

#include <chrono>
#include <iostream>
#include <thread>

int main() {
	try {
		SystemTable sys("./shared_mem");
		sys.setCoords(5,6);
	} catch (const int e) {
		std::cout << e << std::endl;
	}
}
