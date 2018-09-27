/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-09-27
Description:redis client pool not cluster
ChangeLog:
			1. create this file
 **************************************************/

#include "RedisClientPool.h"

RedisClientPool::RedisClientPool()
{
	// TODO Auto-generated constructor stub
}
/*
 * @purpose:init pool
 * @return true if init ok
 * */
bool RedisClientPool::InitPool(const RedisClientPoolConfig &config)
{
	if (config.poolsize > POOLCAPACITY)
	{
		cerr << "pool size is over limit...!" << endl;
		return false;
	}
	for (size_t i = 0;i < config.poolsize;i++)
	{
		unique_ptr<RedisClient>ptr(new RedisClient);
		if (!ptr->Connect(config.ip.c_str(), config.port))
		{
			return false;
		}
		clientVec.push_back(move(ptr));
	}
	return true;
}
/*
 * @purpose:get client from pool
 * */
unique_ptr<RedisClient, DeleteType>RedisClientPool::GetClient()
{
	lock_guard<mutex>lock(pool_lock);
	if (clientVec.empty())
	{
		return nullptr;
	}
	unique_ptr<RedisClient, DeleteType>ptr(clientVec.back().release(), [this](RedisClient *client)
		{
			pool_lock.lock();
			clientVec.push_back(unique_ptr<RedisClient>(client));
			pool_lock.unlock();
	        });
        clientVec.pop_back();
        return move(ptr);
}

RedisClientPool::~RedisClientPool()
{
	// TODO Auto-generated destructor stub
}
