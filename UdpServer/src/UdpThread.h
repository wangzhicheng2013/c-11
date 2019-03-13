/*
 * UdpThread.h
 *
 *  Created on: 2019-3-11
 *      Author: root
 */

#ifndef UDPTHREAD_H_
#define UDPTHREAD_H_
#include "SocketUtility.h"
#include <event.h>
#include <event2/listener.h>
class UdpThread {
public:
	UdpThread();
	virtual ~UdpThread();
public:
	bool Init(int fd);
	void UdpDispatchEvent();
	virtual bool DealUdpMessage(int fd) = 0;
	static void ReadUdpCallBackFun(int fd, short event, void *arg);
protected:
	int sock_fd;
	event_base *pBase;
	event *pEvent;
protected:
	const int buffer_size = 1024;
};

#endif /* UDPTHREAD_H_ */
