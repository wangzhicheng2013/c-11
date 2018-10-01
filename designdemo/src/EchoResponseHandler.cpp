/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-10-01
Description:send echo to http client class
ChangeLog:
			1. create this file
**************************************************/

#include "EchoResponseHandler.h"

EchoResponseHandler::EchoResponseHandler()
{
	// TODO Auto-generated constructor stub

}
/*
 * @purpose:handler http request
 * */
void EchoResponseHandler::Handler(HttpConfig &config)
{
	config.response_body = "echo";
	config.response_code = HTTP_200;

}
EchoResponseHandler::~EchoResponseHandler()
{
	// TODO Auto-generated destructor stub
}
