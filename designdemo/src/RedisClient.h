/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-09-25
Description:redis client not cluster
ChangeLog:
			1. create this file
 **************************************************/

#ifndef REDISCLIENT_H_
#define REDISCLIENT_H_
#include <hiredis/hiredis.h>
#include <iostream>
#include <string>
using namespace std;
class RedisClient
{
public:
	RedisClient();
	/*
	 * @purpose:connect to redis server
	 * @return true if connect ok
	 * */
	bool Connect(const char *ip, int port);
	virtual ~RedisClient();
private:
	redisContext *conn;
};

#endif /* REDISCLIENT_H_ */
