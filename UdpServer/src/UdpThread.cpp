/*
 * UdpThread.cpp
 *
 *  Created on: 2019-3-11
 *      Author: root
 */

#include "UdpThread.h"

UdpThread::UdpThread()
{
	// TODO Auto-generated constructor stub
	pBase = nullptr;
	pEvent = nullptr;
}
bool UdpThread::Init(const SocketConfig &config)
{
	int sock_fd = SocketUtility::GetInstance().BindSocket(config);
	pBase = event_base_new();
	if (nullptr == pBase)
	{
		return false;
	}
	pEvent = event_new(pBase, sock_fd, ReadUdpCallBackFun);
	if (nullptr == pEvent)
	{
		return false;
	}
	return 0 == event_add(pEvent, NULL);
}
void UdpThread::ReadUdpCallBackFun(int fd, short event, void *arg)
{
}
UdpThread::~UdpThread()
{
	// TODO Auto-generated destructor stub

	event_base_loopexit(pBase, NULL);

}
