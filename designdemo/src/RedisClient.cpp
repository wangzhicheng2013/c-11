/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-10-18
Description:redis client not cluster
ChangeLog:
			1. create this file
			2. add Publish method
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
/*
 * @purpose:publish to redis server
 * @return true if publish ok
 * */
bool RedisClient::Publish(const char *channel, const char *message)
{
	if (!CheckPublish(channel, message))
	{
		return false;
	}
	size_t len = strlen(message);
	redisReply *reply = (redisReply *)redisCommand(conn, "publish %s %b", channel, message, len);
	if (nullptr == reply)
	{
		cerr << "reply is null...!" << endl;
		return false;
	}
	bool succ = true;
	if (REDIS_REPLY_NIL == reply->type || REDIS_REPLY_ERROR == reply->type)
	{
		succ = false;
		cerr << "reply error = " << reply->str << endl;
	}
	freeReplyObject(reply);
	reply = nullptr;
	return succ;
}
/*
 * @purpose:subscribe from redis server
 * @return true if subscribe ok
 * */
bool RedisClient::Subscribe(const char *channel, string &message)
{
	if (!CheckSubscribe(channel))
	{
		return false;
	}
	redisReply *reply = (redisReply *)redisCommand(conn, "subscribe %s", channel);
	if (nullptr == reply)
	{
		cerr << "reply is null...!" << endl;
		return false;
	}
	bool succ = false;
	if (REDIS_REPLY_ARRAY == reply->type && 3 == reply->elements)
	{
		if (!strcmp(reply->element[0]->str, "message") && !strcmp(reply->element[1]->str, channel))
		{
			succ = true;
			message.assign(reply->element[2]->str, reply->element[2]->len);
		}
	}
	freeReplyObject(reply);
	reply = nullptr;
	return succ;
}
/*
 * @purpose:check publish
 * @return true if check ok
 * */
bool RedisClient::CheckPublish(const char *channel, const char *message)
{
	if (nullptr == conn)
	{
		cerr << "redis client conn is null...!" << endl;
		return false;
	}
	size_t len = strlen(channel);
	if (len > MAXCHANNELSIZE)
	{
		cerr << "channel size is over 1k...!" << endl;
		return false;
	}
	len = strlen(message);
	if (len > MAXVALUESIZE)
	{
		cerr << "value size is over 1M...!" << endl;
		return false;
	}
	return true;
}
/*
 * @purpose:check subscribe
 * @return true if check ok
 * */
bool RedisClient::CheckSubscribe(const char *channel)
{
	if (nullptr == conn)
	{
		cerr << "redis client conn is null...!" << endl;
		return false;
	}
	size_t len = strlen(channel);
	if (len > MAXCHANNELSIZE)
	{
		cerr << "channel size is over 1k...!" << endl;
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
