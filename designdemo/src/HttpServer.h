/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-10-01
Description:http server class
ChangeLog:
			1. create this file
**************************************************/

#ifndef HTTPSERVER_H_
#define HTTPSERVER_H_
#include "SockectUtility.h"
#include "HttpThread.h"
#include <vector>
#include <thread>
class HttpServer
{
public:
	HttpServer();
	/*
	 * @purpose:init server
	 * @return true if init ok
	 * */
	bool Init(int, const SocketConfig &);
	virtual ~HttpServer();
private:
	/*
	 * @purpose:start http thread
	 * */
	void StartHttpThread(int);
private:
	vector<HttpThread>httpthreadVec;
	vector<thread>threadVec;
	const int NETWORKCAPACITY = 128;
};

#endif /* HTTPSERVER_H_ */
