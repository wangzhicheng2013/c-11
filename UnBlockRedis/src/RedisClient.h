/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2019-01-20
Description:redis client not cluster
ChangeLog:
			1. create this file
			2. add Publish method
			3. add SetNx method
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
	bool Connect(const char *ip = "127.0.0.1", int port = 6379);
	/*
	 * @purpose:set value to redis server
	 * @return true if set ok
	 * */
	bool SetValue(const char *key, const string &value);
	/*
	 * @purpose:set value to redis server when key does not exist
	 * @return true if set ok
	 * */
	bool SetNxValue(const char *key, const char *value, int timeout = 1);
	/*
	 * @purpose:get value from redis server
	 * @return true if get ok
	 * */
	bool GetValue(const char *key, string &value);
	/*
	 * @purpose:delete value from redis server
	 * @return true if get ok
	 * */
	bool DelValue(const char *key);
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
