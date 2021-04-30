#pragma once

#include <netinet/in.h>
#include <netinet/ip.h> 
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstdio>
#include <ctime>

class ExampleClient
{
public:
	ExampleClient(int fd, in_addr client_addr, uint16_t client_port, uint32_t timeout) :
            fd_(fd),
            client_addr_(client_addr),
            client_port_(client_port),
            timeout_(timeout),
		    last_active_(time(nullptr)){}

    //called when a client fd becomes available for writing
	bool ReadReady();

    //called when a client fd becomes available for reading
	static bool WriteReady();

    //called periodically to check if fd is still alive (used to implement timeout)
	bool HeartBeat();

    //called if the connection was forcibly closed by the client
	void ClientClose();

    //called when the server is done with the client and the fd should be closed
	void ServerClose();

    //client's unique id
    int uid() const { return fd_;  }

protected:
    int      fd_;
    in_addr  client_addr_;
    uint16_t client_port_;
    uint32_t timeout_;
	time_t   last_active_;
};