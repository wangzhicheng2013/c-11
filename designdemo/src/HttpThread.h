/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-10-01
Description:http thread class
ChangeLog:
			1. create this file
**************************************************/

#ifndef HTTPTHREAD_H_
#define HTTPTHREAD_H_

#include "SockectUtility.h"
#include "HttpUtility.h"
class HttpThread
{
public:
	HttpThread();
	/*
	 * @purpose:init http thread
	 * @return true if init ok
	 * */
	bool Init(int);
	/*
	 * @purpose:http dispatch event
	 * */
	void HttpDispathEvent();
	virtual ~HttpThread();
private:
	/*
	 * @purpose:http call back function
	 * */
	static void HttpCallBackFun(struct evhttp_request *, void *);
private:
	event_base *pEventBase;
	evhttp *pEventHttp;
	int sock_fd;
};

#endif /* HTTPTHREAD_H_ */
