/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-09-26
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
/*
 * @purpose:set value to redis server
 * @return true if set ok
 * */
bool RedisClient::SetValue(const char *key, const string &value)
{
	if (nullptr == conn)
	{
		cerr << "redis client conn is null...!" << endl;
		return false;
	}
	if (value.size() > MAXVALUESIZE)
	{
		cerr << "value size is over 1M...!" << endl;
		return false;
	}
	size_t keylen = strlen(key);
	if (keylen > MAXKEYSIZE)
	{
		cerr << "key size is over 1k...!" << endl;
		return false;
	}
	redisReply *reply = (redisReply *)redisCommand(conn, "set %b %b", key, keylen, value.c_str(), value.size());
	if (nullptr == reply)
	{
		cerr << "reply is null...!" << endl;
		return false;
	}
	bool succ = true;
	if (nullptr == reply->str)
	{
		succ = false;
		cerr << "reply string is null...!" << endl;
	}
	else if (strcasecmp(reply->str, "ok"))
	{
		succ = false;
		cerr << "reply error = " << reply->str << endl;
	}
	freeReplyObject(reply);
	reply = nullptr;
	return succ;
}
/*
 * @purpose:get value from redis server
 * @return true if get ok
 * */
bool RedisClient::GetValue(const char *key, string &value)
{
	if (nullptr == conn)
	{
		cerr << "redis client conn is null...!" << endl;
		return false;
	}
	size_t keylen = strlen(key);
	if (keylen > MAXKEYSIZE)
	{
		cerr << "key size is over 1k...!" << endl;
		return false;
	}
	redisReply *reply = (redisReply *)redisCommand(conn, "get %s", key);
	if (nullptr == reply)
	{
		cerr << "reply is null...!" << endl;
		return false;
	}
	bool succ = true;
	if (nullptr == reply->str)
	{
		succ = false;
		cerr << "reply string is null...!" << endl;
	}
	else if (REDIS_REPLY_NIL == reply->type)
	{
		succ = false;
		cerr << "reply error = " << reply->str << endl;
	}
	else
	{
		value.assign(reply->str, reply->len);
	}
	freeReplyObject(reply);
	reply = nullptr;
	return succ;
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
