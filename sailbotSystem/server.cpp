#include <iostream>
#include <string>
#include "json.hpp"

// Server stuff:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

using json = nlohmann::json;

int main(void)
{
    
    int sockfd, newsockfd, portno = 2222;
    socklen_t clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;
    
    try{
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	
	if (sockfd < 0) 
	    throw("ERROR opening socket");
	
	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(portno);
	
	if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
	    throw("ERROR on binding");
    } catch(...) {
	exit(1);
    }
   while(true) 
   {
	try{	
	    listen(sockfd,5);
	    clilen = sizeof(cli_addr);
	    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
	    
	    if (newsockfd < 0) 
		throw("ERROR on accept");
	    
	    bzero(buffer,256);
	    n = read(newsockfd,buffer,255);
	    
	    // Put into json
	    std::string msg(buffer, 255);
	    json j = json::parse(msg);

	    if (n < 0) 
		throw("ERROR reading from socket");

	    std::cout 
		<< "Here is the message: " << j.dump(4) << std::endl
	    

	    n = write(newsockfd,"I got your message",18);
	    
	    if (n < 0) 
		throw("ERROR writing to socket");
	
	} catch(...){ 
	    close(newsockfd);
	}
    }

    close(sockfd);
    
    return 0; 
}
