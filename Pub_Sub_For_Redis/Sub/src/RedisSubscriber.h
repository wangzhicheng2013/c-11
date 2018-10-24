/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-10-24
Description:subscriber for redis sub modern
ChangeLog:
			1. create this file
**************************************************/

#ifndef REDISSUBSCRIBER_H_
#define REDISSUBSCRIBER_H_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <hiredis/async.h>
#include <hiredis/adapters/libevent.h>
#include <iostream>
#include <string>
#include <thread>
#include <functional>
using namespace std;
using SubCallBackFun = function<void(const char *, const char *, int)>;
class RedisSubscriber {
public:
	explicit RedisSubscriber(SubCallBackFun &);
	virtual ~RedisSubscriber();
public:
	/*
	 * @purpose:init event base and connect to redis server
	 * @return true if init ok
	 * */
	bool Init(const char * = "127.0.0.1", int = 6379);
	/*
	 * @purpose:subscribe message from redis server
	 * @return true if publish ok
	 * */
	bool Sub(const string &);
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
	 * @purpose:call back function for subscribe to redis
	 * */
	static void SubCallBack(redisAsyncContext *, void *, void *);
private:
	event_base *pBase;
	redisAsyncContext *pCtx;
	thread dispatch_thread;
	SubCallBackFun subCallBackFn;
};

#endif /* REDISPUBLISHER_H_ */
