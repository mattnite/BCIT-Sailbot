// System variable table implementation file

// Author: Matthew Knight
// File Name: varTable.cpp
// Date: 2017-06-05

// This class contains all the system variables in the sailbot. It is intended
// that the task threads in the control system have access to these atomic
// variables and operate on them.

#include "varTable.hpp"

varTable::varTable()
    : gpsPort("5555")
    , gpsCommPort("5554")
{}
