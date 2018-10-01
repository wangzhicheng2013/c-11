/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-10-01
Description:http response handler class
ChangeLog:
			1. create this file
**************************************************/

#ifndef RESPONSEHANDLER_H_
#define RESPONSEHANDLER_H_
#include "HttpConfig.h"
enum HttpResponseCode
{
	HTTP_200 = 200,
	HTTP_201,
	HTTP_404 = 404,
	HTTP_501 = 501,
	HTTP_502 = 502
};
class ResponseHandler
{
public:
	ResponseHandler();
	/*
	 * @purpose:handler http request
	 * */
	virtual void Handler(HttpConfig &) = 0;
	virtual ~ResponseHandler();
};

#endif /* RESPONSEHANDLER_H_ */
