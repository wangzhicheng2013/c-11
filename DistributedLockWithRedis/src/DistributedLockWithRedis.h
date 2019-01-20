/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2019-01-20
Description:distributed lock with redis
ChangeLog:
			1. create this file
 **************************************************/

#ifndef DISTRIBUTEDLOCKWITHREDIS_H_
#define DISTRIBUTEDLOCKWITHREDIS_H_
#include "RedisClient.h"
class DistributedLockWithRedis
{
public:
	DistributedLockWithRedis(RedisClient *, const char *);
	virtual ~DistributedLockWithRedis();
public:
	bool TryLock();
private:
	RedisClient *client;
	bool lock_succ;
	const char *key;
};

#endif /* DISTRIBUTEDLOCKWITHREDIS_H_ */
