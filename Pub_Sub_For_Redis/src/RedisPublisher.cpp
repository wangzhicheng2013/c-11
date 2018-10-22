/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-10-21
Description:publisher for redis pub modern
ChangeLog:
			1. create this file
			2. add constructor method
**************************************************/

#include "RedisPublisher.h"

RedisPublisher::RedisPublisher() {
	// TODO Auto-generated constructor stub
	pBase = nullptr;
	pCtx = nullptr;

}
/*
 * @purpose:call back function for connection of redis
 * */
void RedisPublisher::ConnectCallBack(const redisAsyncContext *context, int status)
{
	if (REDIS_OK != status)
	{
		cerr << context->errstr;
	}
	else
	{
		cout << "redis connect ok" << endl;
	}
}
/*
 * @purpose:call back function for disconnection of redis
 * */
void RedisPublisher::DisconnectCallBack(const redisAsyncContext *context, int status)
{
	if (REDIS_OK != status)
	{
		cerr << context->errstr;
	}
	else
	{
		cout << "redis disconnect ok" << endl;
	}
}
/*
 * @purpose:call back function for publish to redis
 * */
void RedisPublisher::PubCallBack(redisAsyncContext *, void *r, void *p)
{

}
/*
 * @purpose:publish message to redis server
 * @return true if publish ok
 * */
bool RedisPublisher::Pub(const string &channel, const string &message)
{
	int ret = redisAsyncCommand(pCtx,
			RedisPublisher::PubCallBack,
			this,
			"publish %s %s", channel.c_str(), message.c_str());
	if (REDIS_ERR == ret)
	{
		cerr << "publish command execute failed...!" << endl;
		return false;
	}
	return true;
}
/*
 * @purpose:init event base and connect to redis server
 * @return true if init ok
 * */
bool RedisPublisher::Init(const char *ip, int port)
{
	pBase = event_base_new();
	if (nullptr == pBase)
	{
		return false;
	}
	pCtx = redisAsyncConnect(ip, port);
	if (nullptr == pCtx)
	{
		cerr << "can not connect to redis server ip = " << ip << " port = " << port << endl;
		return false;
	}
	if (pCtx->err)
	{
		cerr << "redis connect error = " << pCtx->errstr << endl;
		return false;
	}
	redisLibeventAttach(pCtx, pBase);
	redisAsyncSetConnectCallback(pCtx, RedisPublisher::ConnectCallBack);
	redisAsyncSetDisconnectCallback(pCtx, RedisPublisher::DisconnectCallBack);
	event_base_dispatch(pBase);
	return true;
}
RedisPublisher::~RedisPublisher() {
	// TODO Auto-generated destructor stub
	if (nullptr != pCtx)
	{
		redisAsyncDisconnect(pCtx);
		redisAsyncFree(pCtx);
		pCtx = nullptr;
	}
	if (nullptr != pBase)
	{
		event_base_loopexit(pBase, nullptr);
	}
}
