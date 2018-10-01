/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-10-01
Description:http server class
ChangeLog:
			1. create this file
**************************************************/

#include "HttpServer.h"

HttpServer::HttpServer()
{
	// TODO Auto-generated constructor stub
}
/*
 * @purpose:init server
 * @return true if init ok
 * */
bool HttpServer::Init(int network_size, const SocketConfig &config)
{
	if (network_size <= 0 || network_size > NETWORKCAPACITY)
	{
		cerr << "network size exception...!" << endl;
		return false;
	}
	SockectUtility sockectUtility(config);
	if (!sockectUtility.BindSocket())
	{
		return false;
	}
	httpthreadVec.resize(network_size);
	for (auto &it : httpthreadVec)
	{
		if (!it.Init(sockectUtility.GetSockFd()))
		{
			return false;
		}
	}
	threadVec.resize(network_size);
	for (int i = 0;i < network_size;i++)
	{
		try
		{
			threadVec[i] = thread(bind(&HttpServer::StartHttpThread, this, i));
		}
		catch (...)
		{
			return false;
		}
	}
	return true;
}
/*
 * @purpose:start http thread
 * */
void HttpServer::StartHttpThread(int index)
{
	httpthreadVec[index].HttpDispathEvent();
}
HttpServer::~HttpServer()
{
	// TODO Auto-generated destructor stub
	for (auto &it : threadVec)
	{
		if (it.joinable())
		{
			it.join();
		}
	}
}
