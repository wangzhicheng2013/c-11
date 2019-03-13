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
	sock_fd = -1;
	pBase = nullptr;
	pEvent = nullptr;
}
bool UdpThread::Init(int fd)
{
	if (fd < 0)
	{
		return false;
	}
	sock_fd = fd;
	pBase = event_base_new();
	if (nullptr == pBase)
	{
		return false;
	}
	pEvent = event_new(pBase, sock_fd, EV_READ | EV_PERSIST, ReadUdpCallBackFun, this);
	if (nullptr == pEvent)
	{
		return false;
	}
	return 0 == event_add(pEvent, NULL);
}
void UdpThread::UdpDispatchEvent()
{
	if (pBase != nullptr)
	{
		event_base_dispatch(pBase);
	}
}
void UdpThread::ReadUdpCallBackFun(int fd, short event, void *arg)
{
	UdpThread *pUdpThread = reinterpret_cast<UdpThread *>(arg);
	if (nullptr == pUdpThread)
	{
		return;
	}
	pUdpThread->DealUdpMessage(fd);
}
UdpThread::~UdpThread()
{
	// TODO Auto-generated destructor stub
	if (pBase != nullptr)
	{
		event_base_loopexit(pBase, NULL);
		event_base_free(pBase);
		pBase = nullptr;
	}
	if (pEvent != nullptr)
	{
		event_free(pEvent);
		pEvent = nullptr;
	}
}
