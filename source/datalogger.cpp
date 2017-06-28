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

#define BUFLEN 24

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


