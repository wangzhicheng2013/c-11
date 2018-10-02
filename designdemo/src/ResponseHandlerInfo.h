/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-10-01
Description:response handler information class
ChangeLog:
			1. create this file
**************************************************/

#ifndef RESPONSEHANDLERINFO_H_
#define RESPONSEHANDLERINFO_H_
#include "EchoResponseHandler.h"
#include "HttpUtility.h"
class ResponseHandlerInfo
{
public:
	ResponseHandlerInfo();
	/*
	 * @purpose:use http utility to init
	 * */
	void Init();
	/*
	 * @purpose:init echo response handler
	 * */
	void InitEchoResponseHandler();
	virtual ~ResponseHandlerInfo();
private:
	EchoResponseHandler echoResponseHandler;
};

#endif /* RESPONSEHANDLERINFO_H_ */
