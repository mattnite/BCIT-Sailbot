// Serial Port Class Interface

// Author: Matthew Knight
// Date: 2017-02-07

// This class is used to make a serial port object that will be used in the
// sailbot to interface to the GPS module and the Xbee transciever. By default
// this class will use canonical input mode. Additional device communication
// over UART is anticipated, however extra functionality can be added later.

#include <termios.h>
#include <string>

#define BUFLEN 255

class Serial
{
    struct termios newtio, oldtio;	// Termios structs to save old and new
					// settings for port
    int device;				// File pointer to device
    char buf[BUFLEN];

public:    
    // ctor
    Serial(char* devFile);

    // Read line from port
    int get();

    // Write line to port
    void send(char* data);

    // dtor
    ~Serial();
};
