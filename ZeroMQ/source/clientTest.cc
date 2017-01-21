// Client Test Program

// Author: Matthew Knight]
// Date: 2017-01-20

// This program is for testing ZeroMQ on the client side of things. This
// will be used extensively in the sailbot for inter-process communciation.

#include <zmq.hpp>
#include <string>
#include <iostream>

int main()
{
    // prepare context and socket
    zmq::context_t context(1);
    zmq::socket_t socket(context, ZMQ_REQ);

    std::cout << "Connecting to sailbot server..." << std::endl;
    socket.connect("tcp://localhost:5555");

    // Do 10 requests, waiting each time for a response
    for (int request_nbr = 0; request_nbr < 10; request_nbr++)
    {
	zmq::message_t request(5);
	memcpy(request.data(), "Hello", 5);
	std::cout << "Sending Hello " << request_nbr << " ..." << std::endl;
	socket.send(request);

	// get the reply
	zmq::message_t reply;
	socket.recv(&reply);
	std::cout << "Recieved World " << request_nbr << std::endl;
    }
    return 0;
}
