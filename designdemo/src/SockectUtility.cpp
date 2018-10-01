/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-10-01
Description:socket utility class
ChangeLog:
			1. create this file
**************************************************/

#include "SockectUtility.h"
SocketConfig::SocketConfig()
{
	ip = "127.0.0.1";
	port = 8888;
	backlog = 1024;
}
SocketConfig::~SocketConfig()
{
}
SockectUtility::SockectUtility(const SocketConfig &_config) : config(_config)
{
	// TODO Auto-generated constructor stub
	sock_fd = -1;
}
/*
 * @purpose:init socket
 * @return true if init ok
 * */
bool SockectUtility::InitSocket()
{
	sock_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (sock_fd < 0)
	{
		cerr << "socket fd create failed...!" << endl;
		return false;
	}
	int on = 1;
	if (setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, (char *)&on, sizeof(on)) < 0)
	{
		cerr << "set socket to resue failed...!" << endl;
		return false;
	}
	if (setsockopt(sock_fd, SOL_SOCKET, SO_KEEPALIVE, (char *)&on, sizeof(on)) < 0)
	{
		cerr << "set socket to keep alive failed...!" << endl;
		return false;
	}
	return true;
}
/*
 * @purpose:bind socket
 * @return true if bind ok
 * */
bool SockectUtility::BindSocket()
{
	struct sockaddr_in addr = {0};
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr(config.ip.c_str());
	addr.sin_port = htons(config.port);
	if (bind(sock_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0)
	{
		cerr << "socket bind failed on ip = " << config.ip << " port = " << config.port << endl;
		return false;
	}
	if (listen(sock_fd, config.backlog) < 0)
	{
		cerr << "socket listen failed on backlog = " << config.backlog << endl;
		return false;
	}
	int flag = 0;
	flag = fcntl(sock_fd, F_GETFL, 0);
	if (flag < 0)
	{
		cerr << "fcntl F_GETFL on socket = " << sock_fd << " failed...!" << endl;
		return false;
	}
	if (fcntl(sock_fd, F_SETFL, flag | O_NONBLOCK) < 0)
	{
		cerr << "fcntl F_SETFL non block on socket = " << sock_fd << " failed...!" << endl;
		return false;
	}
	return true;
}
SockectUtility::~SockectUtility()
{
	// TODO Auto-generated destructor stub
	if (sock_fd >= 0)
	{
		close(sock_fd);
		sock_fd = -1;
	}
}
