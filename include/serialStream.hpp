// Serial Stream Wrapper

// Author: Matthew Knight
// File Name: serialStream.hpp
// Date: 2017-06-08

// This class acts as a wrapper and interface for the termios functions. Class
// methods are named directly after functions, however the file descriptor and
// termios struct are encapsulated which simplifies interface. This class saves
// the original attributes and returns them as it found them when it destructs.
// tcgetattr is only needed in the constructor and is not included in the
// Methods.

#ifndef SERIALSTREAM_H_
#define SERIALSTREAM_H_

#include <termios.h>
#include <string>
#include <sstream>

class serialStream
{
    int fd;				// File Descriptor
    const struct termios *old, *new;
    string in, out;

public:
    // ctor
    serialStream(const char *file);

// TERMIOS FUNCTIONS

    // Set attributes
    int tcsetattr(int optional_actions);
    
    // Send break
    int tcsendbreak(int duration);

    // Drain
    int tcdrain();

    // Flush
    int tcflush(int queue_selector);

    // Flow
    int tcflow(int action);

    // Make Raw
    void cfmakeraw();

    // Get in speed
    speed_t cfgetispeed();

    // Get out speed
    speed_t cfgetospeed();

    // Set in speed
    int setispeed(speed_t speed);
    
    // Set out speed
    int setospeed(speet_t speed);

    // Set speed
    int setspeed(speed_t speed);

// INPUT/OUTPUT OPERATIONS

    // dtor
    ~serialStream();
};

#endif
