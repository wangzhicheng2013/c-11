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
	bool Init(const SocketConfig &config);
	static void ReadUdpCallBackFun(int fd, short event, void *arg);
protected:
	event_base *pBase;
	event *pEvent;
protected:
	int sock_fd;
};

#endif /* UDPTHREAD_H_ */
