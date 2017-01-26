// GPS Server Program

// Author: Matthew Knight
// Date: 2017-01-21

// This program polls the gps periodically to update the current latitude and
// longitude. Inbetween these polls, the server listens for any requests from
// other processes and returns the last determined coordinates of the sailbot. 
// The polling frequency is dependent on the battery charge.

#include <zmq.hpp>
#include <string>
#include <iostream>
#ifndef _WIN32
#include <unistd.h>
#else 
#include <windows.h>
#define sleep(n) Sleep(n)
#endif

#include <thread>
#include <atomic>

// This thread coninuously waits for requests for gps coordinates and 
void *server(int portNum)
{
    // Initialize Server
    zmq::context_t context(1);
    zmq::socket_t socket(context, ZMQ_REP);
    
    socket.bind("tcp://*:5555");
    std::cout << "GPS: Server Initialized on port " << portNum << std::endl;

    // Run server forever
    while (true)
    {
	const char *coord = "latitude, longitude";
	zmq::message_t request;
	
	socket.recv(&request);
	std::cout << "GPS: Request Recieved" << std::endl;
	zmq::message_t reply(5);
	memcpy(reply.data(), coord, 5);
	socket.send(reply);
    }
}

// Main Thread, sets everything up and polls GPS
int main(int argc, char* argv[])
{
    // Arguments to program: gps port
    int gpsPort = 5555;

    // Start up UART
    std::cout << "GPS: UART initialized" << std::endl;
    
    // Initialize Coordinates

    std::cout << "GPS: Coordinates initialized" << std::endl;
    
    // Start Server Thread
    std::thread gpsServer(server, gpsPort);
    std::cout << "GPS: Created Thread for server" << std::endl;
    
    // update Coordinates
    while (true)
    {
	std::cout << "GPS: Getting Coordinates..." << std::endl;
	std::cout << "GPS: Coordinates Updated" << std::endl;
	sleep(1);
    }

    return 0;
}


