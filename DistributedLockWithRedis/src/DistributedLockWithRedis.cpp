/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2019-01-20
Description:distributed lock with redis
ChangeLog:
			1. create this file
 **************************************************/
#include "DistributedLockWithRedis.h"

DistributedLockWithRedis::DistributedLockWithRedis(RedisClient *client, const char *key)
{
	// TODO Auto-generated constructor stub
	this->client = client;
	this->key = key;
	lock_succ = false;
}
bool DistributedLockWithRedis::TryLock()
{
	if (nullptr == client)
	{
		return false;
	}
	if (!client->SetNxValue(key, "0"))
	{
		return false;
	}
	lock_succ = true;
	return true;
}
DistributedLockWithRedis::~DistributedLockWithRedis()
{
	// TODO Auto-generated destructor stub
	if (nullptr != client && true == lock_succ)
	{
		client->DelValue(key);
	}
}
