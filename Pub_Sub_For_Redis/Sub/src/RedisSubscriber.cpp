/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-10-24
Description:subscriber for redis sub modern
ChangeLog:
			1. create this file
**************************************************/

#include "RedisSubscriber.h"

RedisSubscriber::RedisSubscriber(SubCallBackFun &fun) {
	// TODO Auto-generated constructor stub
	pBase = nullptr;
	pCtx = nullptr;
	subCallBackFn = fun;
}
/*
 * @purpose:call back function for connection of redis
 * */
void RedisSubscriber::ConnectCallBack(const redisAsyncContext *context, int status)
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
void RedisSubscriber::DisconnectCallBack(const redisAsyncContext *context, int status)
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
 * @purpose:call back function for subscribe to redis
 * */
void RedisSubscriber::SubCallBack(redisAsyncContext *, void *reply, void *private_data)
{
	if (nullptr == reply || nullptr == private_data)
	{
		cerr << "reply or private data is null...!" << endl;
		return;
	}
	RedisSubscriber *self_ptr = reinterpret_cast<RedisSubscriber *>(private_data);
	redisReply *reply_ptr = reinterpret_cast<redisReply *>(reply);
	if (REDIS_REPLY_ARRAY == reply_ptr->type && 3 == reply_ptr->elements)
	{
		if (0 == strcmp(reply_ptr->element[0]->str, "subscribe"))
		{
			return;
		}
		self_ptr->subCallBackFn(reply_ptr->element[1]->str,	// channel
				reply_ptr->element[2]->str,					// message
				reply_ptr->element[2]->len);				// message length
	}
}
/*
 * @purpose:subscribe message from redis server
 * @return true if publish ok
 * */
bool RedisSubscriber::Sub(const string &channel)
{
	int ret = redisAsyncCommand(pCtx,
			RedisSubscriber::SubCallBack,
			this,
			"subscribe %s %s", channel.c_str());
	if (REDIS_ERR == ret)
	{
		cerr << "subscribe command execute failed...!" << endl;
		return false;
	}
	return true;
}
/*
 * @purpose:init event base and connect to redis server
 * @return true if init ok
 * */
bool RedisSubscriber::Init(const char *ip, int port)
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
	redisAsyncSetConnectCallback(pCtx, RedisSubscriber::ConnectCallBack);
	redisAsyncSetDisconnectCallback(pCtx, RedisSubscriber::DisconnectCallBack);
	try
	{
		dispatch_thread = thread([this](){
			event_base_dispatch(pBase);
		});
	}
	catch (...)
	{
		return false;
	}
	return true;
}
RedisSubscriber::~RedisSubscriber() {
	// TODO Auto-generated destructor stub
	if (dispatch_thread.joinable())
	{
		dispatch_thread.join();
	}
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
    if (nullptr != pBase)
    {
    	event_base_free(pBase);
    	pBase = nullptr;
    }
}
