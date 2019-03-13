/*
 * UdpServer.h
 *
 *  Created on: 2019-3-13
 *      Author: root
 */

#ifndef UDPSERVER_H_
#define UDPSERVER_H_
#include <vector>
#include <thread>
#include <memory>
#include "UdpTheadForRadius.h"

class UdpServer {
public:
	UdpServer(const SocketConfig &config);
	virtual ~UdpServer();
public:
	bool Init(int = -1);
private:
	void StartUdpThread(int);
private:
	SocketConfig config;
	vector<unique_ptr<UdpThread> >vecUdpthreads;
	vector<thread>vecThreads;
private:
	int sock_fd;
private:
	const int network_capacity = 128;
};

#endif /* UDPSERVER_H_ */
