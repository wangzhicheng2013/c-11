/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-09-26
Description:redis client not cluster
ChangeLog:
			1. create this file
 **************************************************/

#ifndef REDISCLIENT_H_
#define REDISCLIENT_H_
#include <hiredis/hiredis.h>
#include <string.h>
#include <iostream>
#include <string>
using namespace std;
class RedisClient
{
public:
	RedisClient();
	RedisClient(const RedisClient &) = delete;
	RedisClient & operator = (const RedisClient &) = delete;
	/*
	 * @purpose:connect to redis server
	 * @return true if connect ok
	 * */
	bool Connect(const char *ip, int port);
	/*
	 * @purpose:set value to redis server
	 * @return true if set ok
	 * */
	bool SetValue(const char *key, const string &value);
	/*
	 * @purpose:get value from redis server
	 * @return true if get ok
	 * */
	bool GetValue(const char *key, string &value);
	virtual ~RedisClient();
private:
	redisContext *conn;
	static const size_t MAXVALUESIZE = 1024 * 1024;
	static const size_t MAXKEYSIZE = 1024;
};

#endif /* REDISCLIENT_H_ */
