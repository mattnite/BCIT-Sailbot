// System Table Interface
//
// Author: Matthew Knight
// File Name: system-table.hpp
// Date: 2018-10-10
//
// This class manages the semaphores and shared memory where the system table is
// located.

#ifndef SYSTEM_TABLE_HPP
#define SYSTEM_TABLE_HPP

#include "table.hpp"


class SystemTable {
	Table *t;
	int shmid, semid;
	const char *p;
	
public:
	// The table can be found using a pathname
	SystemTable(const char *pathname);
	
	// Get copy of the table
	Table getTable();
	
	// Set coordinates
	void setCoords(double lat, double lon);

	// dtor destructs table if it's no longer there.
	~SystemTable();
};

#endif
