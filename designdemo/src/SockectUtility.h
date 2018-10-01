/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-10-01
Description:socket utility class
ChangeLog:
			1. create this file
**************************************************/

#ifndef SOCKECTUTILITY_H_
#define SOCKECTUTILITY_H_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <string>
using namespace std;
class SocketConfig
{
public:
	SocketConfig();
	~SocketConfig();
public:
	string ip;
	int port;
	int backlog;
};
class SockectUtility
{
public:
	SockectUtility(const SocketConfig &);
	/*
	 * @purpose:init socket
	 * @return true if init ok
	 * */
	bool InitSocket();
	/*
	 * @purpose:bind socket
	 * @return true if bind ok
	 * */
	bool BindSocket();
	/*
	 * @purpose:get socket fd
	 * */
	inline int GetSockFd() const
	{
		return sock_fd;
	}
	virtual ~SockectUtility();
private:
	int sock_fd;
	const SocketConfig &config;
};

#endif /* SOCKECTOP_H_ */
