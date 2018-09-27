/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-09-27
Description:redis client pool not cluster
ChangeLog:
			1. create this file
 **************************************************/

#ifndef REDISCLIENTPOOL_H_
#define REDISCLIENTPOOL_H_
#include "RedisClient.h"
#include <vector>
#include <memory>
#include <functional>
#include <mutex>
class RedisClientPoolConfig
{
public:
	size_t poolsize;
	string ip;
	int port;
};
using DeleteType = function<void(RedisClient *)>;
class RedisClientPool
{
public:
	RedisClientPool();
	/*
	 * @purpose:init pool
	 * @return true if init ok
	 * */
	bool InitPool(const RedisClientPoolConfig &);
	/*
	 * @purpose:get client from pool
	 * */
	unique_ptr<RedisClient, DeleteType>GetClient();
	virtual ~RedisClientPool();
private:
	vector<unique_ptr<RedisClient> >clientVec;
	static const size_t POOLCAPACITY = 128;
	mutex pool_lock;
};

#endif /* REDISCLIENTPOOL_H_ */
