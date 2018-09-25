/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-09-25
Description:redis client not cluster
ChangeLog:
			1. create this file
 **************************************************/

#include "RedisClient.h"

RedisClient::RedisClient()
{
	// TODO Auto-generated constructor stub
	conn = nullptr;
}
/*
 * @purpose:connect to redis server
 * @return true if connect ok
 * */
bool RedisClient::Connect(const char *ip, int port)
{
	conn = redisConnect(ip, port);
	if (nullptr == conn)
	{
		cout << "connection is null...!" << endl;
		return false;
	}
	if (conn->err)
	{
		cout << "connection failed err = " << conn->errstr << endl;
		return false;
	}
	return true;
}
RedisClient::~RedisClient()
{
	// TODO Auto-generated destructor stub
	if (nullptr != conn)
	{
		redisFree(conn);
		conn = nullptr;
	}
}
