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
#include "varTable.hpp"

// Helper function for creating timestamp string in UTC.
string time_stamp(std::chrono::system_clock::time_point time);

// datalogger class
class datalogger
{
    varTable *systemVar;
    int flags;

public:
    // ctor
    datalogger(varTable *system, int newFlags);

    // set flags
    void set(int newFlags);

    // clear flags
    void clear(int newFlags);

    // header gives column names
    string header();

    // csv line of selected variables
    string sample();
};

#endif
