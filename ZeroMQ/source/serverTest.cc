// Server Test Program

// Author: Matthew Knight
// Date: 2017-01-20

// This program is simply for practice for using the ZeroMQ library. This
// library will be used extensively in the sailbot control system for
// inter-process communcation

#include <zmq.hpp>
#include <string>
#include <iostream>
#ifndef _WIN32
#include <unistd.h>
#else 
#include <windows.h>
#define sleep(n) Sleep(n)
#endif

int main()
{
   int wait = 5000;
   zmq::context_t context(1);
   zmq::socket_t socket(context, ZMQ_REP);
   socket.bind("tcp://*:5555");

   while (true)
   {
	zmq::message_t request;

	// wait for next request
	if (socket.recv(&request) == EAGAIN)
	    std::cout << "Timed Out" << std::endl;
	else
	{
	    std::cout << "Recieved Hello" << std::endl;
	
	    // Do "work"
	    sleep(1);
	
	    // Send Reply to client
	    zmq::message_t reply(5);
	    memcpy(reply.data(), "World", 5);
	    socket.send(reply);
	}
   }
   return 0;
}
