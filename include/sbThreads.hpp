// Sailbot Thread header

// Author: Matthew Knight
// File Name: sbThreads.hpp
// Date: 2017-06-27

// This header simply contains all the function definitions for all the theads
// for the sailbot control system. Each task will have its own file that will
// include this header.

#ifndef SBTHREAD_H_
#define SBTHREAD_H_

#include "varTable.hpp"

// GPS polling thread, this thread updates the gps coordinates
void gps(varTable *systemVar);

// IMU polling thread
void imu(varTable *systemVar);

// Wind polling thread
void wind(varTable *systemVar);

// Pathfinding thread
void path(varTable *systemVar);

#endif
