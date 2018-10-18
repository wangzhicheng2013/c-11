/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-10-18
Description:redis client not cluster
ChangeLog:
			1. create this file
			2. add Publish method
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
	/*
	 * @purpose:publish to redis server
	 * @return true if publish ok
	 * */
	bool Publish(const char *, const char *);
	/*
	 * @purpose:subscribe from redis server
	 * @return true if subscribe ok
	 * */
	bool Subscribe(const char *, string &);
	/*
	 * @purpose:check publish
	 * @return true if check ok
	 * */
	bool CheckPublish(const char *, const char *);
	/*
	 * @purpose:check subscribe
	 * @return true if check ok
	 * */
	bool CheckSubscribe(const char *);
	virtual ~RedisClient();
private:
	redisContext *conn;
	static const size_t MAXVALUESIZE = 1024 * 1024;
	static const size_t MAXKEYSIZE = 1024;
	static const size_t MAXCHANNELSIZE = 10;
};

#endif /* REDISCLIENT_H_ */
