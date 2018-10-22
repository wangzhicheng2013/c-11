/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-10-21
Description:publisher for redis pub modern
ChangeLog:
			1. create this file
			2. add constructor method
**************************************************/

#ifndef REDISPUBLISHER_H_
#define REDISPUBLISHER_H_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <hiredis/async.h>
#include <hiredis/adapters/libevent.h>
#include <iostream>
#include <string>
using namespace std;
class RedisPublisher {
public:
	RedisPublisher();
	virtual ~RedisPublisher();
public:
	/*
	 * @purpose:init event base and connect to redis server
	 * @return true if init ok
	 * */
	bool Init(const char * = "127.0.0.1", int = 6379);
	/*
	 * @purpose:publish message to redis server
	 * @return true if publish ok
	 * */
	bool Pub(const string &, const string &);
private:
	/*
	 * @purpose:call back function for connection of redis
	 * */
	static void ConnectCallBack(const redisAsyncContext *, int);
	/*
	 * @purpose:call back function for disconnection of redis
	 * */
	static void DisconnectCallBack(const redisAsyncContext *, int);
	/*
	 * @purpose:call back function for publish to redis
	 * */
	static void PubCallBack(redisAsyncContext *, void *, void *);
private:
	event_base *pBase;
	redisAsyncContext *pCtx;
};

#endif /* REDISPUBLISHER_H_ */
