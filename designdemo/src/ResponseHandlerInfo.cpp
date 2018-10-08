/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-10-01
Description:response handler information class
ChangeLog:
			1. create this file
**************************************************/

#include "ResponseHandlerInfo.h"

ResponseHandlerInfo::ResponseHandlerInfo()
{
	// TODO Auto-generated constructor stub

}
/*
 * @purpose:use http utility to init
 * */
void ResponseHandlerInfo::Init()
{
	InitEchoResponseHandler();
}
/*
 * @purpose:init echo response handler
 * */
void ResponseHandlerInfo::InitEchoResponseHandler()
{
	HttpKey key(GET, DEVICE);
	HttpUtility::RegisterHandler(key, &echoResponseHandler);
}
ResponseHandlerInfo::~ResponseHandlerInfo()
{
	// TODO Auto-generated destructor stub
}
