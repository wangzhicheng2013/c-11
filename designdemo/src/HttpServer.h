/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-10-02
Description:http server class
ChangeLog:
			1.create this file
			2.update constructor to add class member
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
	explicit HttpServer(const SocketConfig &);
	/*
	 * @purpose:init server
	 * @return true if init ok
	 * */
	bool Init(int = 1);
	virtual ~HttpServer();
private:
	/*
	 * @purpose:start http thread
	 * */
	void StartHttpThread(int);
private:
	SockectUtility sockectUtility;
	vector<HttpThread>httpthreadVec;
	vector<thread>threadVec;
	const int NETWORKCAPACITY = 128;
};

#endif /* HTTPSERVER_H_ */
