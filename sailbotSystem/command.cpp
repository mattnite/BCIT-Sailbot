// Single command client

// Author: Matthew Knight
// File Name: command.cpp
// Date: 2017-08-12

// This program sends a single command line argument to the sailbot server as a
// JSON object

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/sockets.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <netdb.h>
#include <json.hpp>

#define SOCK_PATH "echo_socket"

using nlohmann::json;

int main(int argc, char *argv[])
{
    // Check number of arguments
    if (argc < 2 || argc > 3)
    {
	std::cout << "Incorrect number of arguments" << std::end;
	return -1;
    }
    
    // Build JSON object
    json req;
    req["command"] = argv[1];
    
    if (argc == 3)
	req["arg"] = argv[2];

    // Create socket
    int s, t len;
    struct sockaddr_un remote;
    char str[100];

    if ((s = socket(

    return 0;
}
