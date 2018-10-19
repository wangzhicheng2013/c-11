/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-10-19
Description:publisher for redis pub modern
ChangeLog:
			1. create this file
**************************************************/

#ifndef REDISPUBLISHER_H_
#define REDISPUBLISHER_H_
#include <hiredis/async.h>
#include <hiredis/adapters/libevent.h>
#include <iostream>
using namespace std;
class RedisPublisher {
public:
	RedisPublisher();
	virtual ~RedisPublisher();
private:
	/*
	 * @purpose:call back function for connection of redis
	 * */
	static void ConnectCallBack(const redisAsynContext *, int);
	/*
	 * @purpose:call back function for disconnection of redis
	 * */
	static void DisconnectCallBack(const redisAsynContext *, int);
	/*
	 * @purpose:call back function for publish to redis
	 * */
	static void PubCallBack(const redisAsynContext *, void *, void *);
private:
	event_base *pBase;
	redisAsynContext *pCtx;
};

#endif /* REDISPUBLISHER_H_ */
