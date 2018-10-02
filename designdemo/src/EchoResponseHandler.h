/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-10-01
Description:send echo to http client class
ChangeLog:
			1. create this file
**************************************************/

#ifndef ECHORESPONSEHANDLER_H_
#define ECHORESPONSEHANDLER_H_

#include "ResponseHandler.h"

class EchoResponseHandler: public ResponseHandler
{
public:
	EchoResponseHandler();
	/*
	 * @purpose:handler http request
	 * */
	virtual void Handler(HttpConfig &) override;
	virtual ~EchoResponseHandler();
};

#endif /* ECHORESPONSEHANDLER_H_ */
