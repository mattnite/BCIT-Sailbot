// Serial Port Class Implementation

// Author: Matthew Knight
// Date: 2017-02-07

// This class is used to make a serial port object that will be used in the
// sailbot to interface to the GPS module and the Xbee transciever. By default
// this class will use canonical input mode. Additional device communication
// over UART is anticipated, however extra functionality can be added later.


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>
#include "../include/Serial.h"
#include <iostream>

#define BAUDRATE B115200

// ctor
Serial::Serial(char* devFile)
{
    // Open the device file for reading and writing
    device = open(devFile, O_RDWR | O_NOCTTY);
    if (device < 0)
    {
	std::cerr << "Failed to open port" << std::endl;
    }
    
    // Copy current settings, clear new settings
    tcgetattr(device, &oldtio);
    bzero(&newtio, sizeof(newtio));

    newtio.c_iflag = BAUDRATE | CRTSCTS | CS8 | CLOCAL | CREAD;
    newtio.c_iflag = IGNPAR | ICRNL;
    newtio.c_oflag = 0;
    newtio.c_lflag = ICANON;

    // Clean modem line
    tcflush(device, TCIFLUSH);

    // Activate new settings for port
    tcsetattr(device, TCSANOW, &newtio);
}

// Read line from port
int Serial::get()
{
    int res = read(device, buf, BUFLEN);
    buf[res] = 0;
}

// Write line to port
void Serial::send(char* data)
{
    if (strlen(data) < BUFLEN)
    {
	strcpy(buf, data);
	write(device, buf, strlen(data));
    }
    else
	std::cerr << "String is too long" << std::endl;
}

// dtor
Serial::~Serial()
{
    // Activate original settings for the port and close it
    tcsetattr(device, TCSANOW, &oldtio);
    close(device);
}
