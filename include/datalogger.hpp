// Datalogger class

// Author: Matthew Knight
// File Name: datalogger.hpp
// Date: 2017-06-28

// This class generates csv lines to be either written to a file, or sent to
// the console interface of the sailbot.

#ifndef DATALOGGER_H_
#define DATALOGGER_H_

#include <string>
#include <chrono>

// Helper function for creating timestamp string in UTC.
string time_stamp(std::chrono::system_clock::time_point time);

#endif
