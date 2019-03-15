/*
 * UdpServer.cpp
 *
 *  Created on: 2019-3-13
 *      Author: root
 */

#include "UdpServer.h"

UdpServer::UdpServer(const SocketConfig &config)
{
	// TODO Auto-generated constructor stub
	sock_fd = -1;
	this->config = config;
}
bool UdpServer::Init(int network_size)
{
	if (network_size <= 0 || network_size > network_capacity)
	{
		return false;
	}
	sock_fd = SocketUtility::GetInstance().BindSocket(config);
	if (sock_fd < 0)
	{
		return false;
	}
	vecThreads.resize(network_size);
	for (int i = 0;i < network_size;i++)
	{
		vecUdpthreads.emplace_back(unique_ptr<UdpThread>(new UdpTheadForRadius));
		if (false == vecUdpthreads[i]->Init(sock_fd))
		{
			cerr << "udp thread init failed...!" << endl;
			continue;
		}
		try
		{
			vecThreads[i] = thread(bind(&UdpServer::StartUdpThread, this, i));
		}
		catch (...)
		{
			return false;
		}
	}

	return true;
}
void UdpServer::StartUdpThread(int index)
{
	vecUdpthreads[index]->UdpDispatchEvent();
}
UdpServer::~UdpServer()
{
	// TODO Auto-generated destructor stub
	for (auto &it : vecThreads)
	{
		if (it.joinable())
		{
			it.join();
		}
	}
	SocketUtility::GetInstance().CloseSocket(sock_fd);
}
