// Datalogger class

// Author: Matthew Knight
// File Name: datalogger.cpp
// Date: 2017-06-28

// This class generates csv lines to be either written to a file, or sent to
// the console interface of the sailbot.

#include <string>
#include <chrono>
#include <ctime>
#include <cstdio>
#include "varTable.hpp"
#include "datalogger.hpp"

// buffer length for timestamp
#define BUFLEN 24

// Datalogging flags
#define D_POS	    0x01
#define D_POS_ERR   0x02
#define D_ACC	    0x04
#define D_HEAD	    0x08
#define D_QUAT	    0x10
#define D_W_SPD	    0x20
#define D_W_DIR	    0x40

using namespace std::chrono;

// Helper function for creating timestamp string in UTC.
string time_stamp(system_clock::time_point time)
{
    // get milliseconds count
    system_clock::duration tp = time.time_since_epoch();
    tp -=duration_cast<seconds>(tp);
    tm t = gmtime(time.to_time_t());
    
    // allocate space for string
    char buf[BUFLEN];
    
    // format entire string
    snprintf(buf, BUFLEN, "%04u-%02u-%02u %02u:%02u:%02u.%03u",
	t.tm_year + 1900,
	t.tm_mon,
	t.tm_mday,
	t.tm_hour,
	t.tm_min,
	t.tm_sec,
	static_cast<unsigned>(tp/milliseconds(1))
    );
    
    return string(buf);
}

// datalogger ctor
datalogger::datalogger(varTable *system, int newFlags)
    : systemVar(system)
    , flags(newFlags)
{}

// set flags
void datalogger::set(int newFlags)
{
    flags |= newFlags;
}

// clear flags
void datalogger::clear(int newFlags)
{
    flags &= ~newFlags;
}

// Make header
string datalogger::header()
{
    string buf;
    sstream line;
    
    line << "Date/Time,";

    if (flags & D_POS)
	line << "Latitude,Longitude,";
    if (flags & D_POS_ERR)
	line << "Latitude Error,Longitude Error,";
    if (flags & D_ACC)
	line << "Acc_x,Acc_y,Acc_z,";
    if (flags & D_HEAD)
	line << "Quat_i,Quat_j,Quat_k,";
    if (flags & D_QUAT)
	line << "Heading,";
    if (flags & D_W_SPD)
	line << "Wind Speed,";
    if (flags & D_W_DIR)
	line << "Wind Direction,";

    // delete last comma and end line
    buf.pop_back();
    line << std::endl;

    return buf;
}

// sample variables
string datalogger::sample()
{
    string buf;
    sstream line;

    line << time_stamp(system_clock::now()) << ",";

    if (flags & D_POS)
	line << pos << ",";
    if (flags & D_POS_ERR)
	line << error << ",";
    if (flags & D_ACC)
	line << linAcc << ",";
    if (flags & D_HEAD)
	line << heading << ",";
    if (flags & D_QUAT)
	line << quat << ",";
    if (flags & D_W_SPD)
	line << windSpeed << ",";
    if (flags & D_W_DIR)
	line << windDir << ",";
    
    // delete last comma and end line
    buf.pop_back();
    line << std::endl;

    return buf;
}
