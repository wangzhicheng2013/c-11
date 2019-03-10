/*
 * SocketUtility.h
 *
 *  Created on: 2019-3-10
 *      Author: root
 */
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
#include "SocketConfig.h"
class SockectUtility
{
public:
	static SockectUtility &GetInstance()
	{
		return sockectUtility;
	}
	/*
	 * @purpose:bind socket
	 * @return socket fd
	 * */
	int BindSocket(const SocketConfig &config);
	bool CloseSocket(int &sock_fd);
private:
	SockectUtility();
	virtual ~SockectUtility();
private:
	/*
	 * @purpose:init socket
	 * @return socket fd
	 * */
	int InitSocket(unsigned char type = UDP);
private:
	static SockectUtility sockectUtility;
};

#endif /* SOCKECTOP_H_ */
