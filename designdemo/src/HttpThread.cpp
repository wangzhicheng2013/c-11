/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-10-01
Description:http thread class
ChangeLog:
			1. create this file
**************************************************/

#include "HttpThread.h"

HttpThread::HttpThread()
{
	// TODO Auto-generated constructor stub
	pEventBase = nullptr;
	pEventHttp = nullptr;
	sock_fd = -1;
}
/*
 * @purpose:init http thread
 * @return true if init ok
 * */
bool HttpThread::Init(int fd)
{
	sock_fd = fd;
	if (sock_fd < 0)
	{
		cerr << sock_fd << " is invalid...!" << endl;
		return false;
	}
	pEventBase = event_base_new();
	if (nullptr == pEventBase)
	{
		return false;
	}
	pEventHttp = evhttp_new(pEventBase);
	if (nullptr == pEventHttp)
	{
		return false;
	}
	if (evhttp_accept_socket(pEventHttp, sock_fd))
	{
		cerr << "http accept on sock = " << sock_fd << " failed...!" << endl;
		return false;
	}
	evhttp_set_gencb(pEventHttp, &HttpThread::HttpCallBackFun, NULL);
	return true;
}
/*
 * @purpose:http dispatch event
 * */
void HttpThread::HttpDispathEvent()
{
	if (pEventBase != nullptr)
	{
		event_base_dispatch(pEventBase);
	}

}
/*
 * @purpose:http call back function
 * */
void HttpThread::HttpCallBackFun(struct evhttp_request *req, void *arg)
{
	HttpUtility httpUtility(req);
	httpUtility.HandleHttp();
}
HttpThread::~HttpThread()
{
	// TODO Auto-generated destructor stub
	if (nullptr != pEventBase)
	{
		event_base_loopexit(pEventBase, NULL);
	}
	if (nullptr != pEventHttp)
	{
		evhttp_free(pEventHttp);
		pEventHttp = nullptr;
	}
	if (nullptr != pEventBase)
	{
		event_base_free(pEventBase);
		pEventBase = nullptr;
	}
}
