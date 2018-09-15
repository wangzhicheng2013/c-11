/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-09-14
Description:kafka client pool
ChangeLog:
			1. create this file
**************************************************/

#ifndef KAFKACLIENTPOOL_H_
#define KAFKACLIENTPOOL_H_
#include <mutex>
using namespace std;
const static int POOLCAPACITY = 64;
template <class ClientType>
class KafkaClientPool
{
public:
	KafkaClientPool()
	{
		clients = nullptr;
	}
	bool Init(int size, const KafkaClientConfig &kafkaClientConfig)
	{
		if (size <= 0 || size > POOLCAPACITY)
		{
			return false;
		}
		poolsize = size;
		clients = new ClientType[poolsize];
		if (nullptr == clients)
		{
			return false;
		}
		for (int i = 0;i < poolsize;i++)
		{
			if (!clients[i].Init(kafkaClientConfig))
			{
				return false;
			}
		}
		return true;
	}
	ClientType *GetClient()
	{
		lock_guard<mutex>guard(lock);
		for (int i = 0;i < poolsize;i++)
		{
			if (false == clients[i].used)
			{
				clients[i].used = true;
				return &clients[i];
			}
		}
		return nullptr;
	}
	void FreeClient(ClientType *client)
	{
		if (nullptr == client)
		{
			return;
		}
		lock_guard<mutex>guard(lock);
		client->used = false;
	}
	KafkaClientPool(const KafkaClientPool &) = delete;
	KafkaClientPool & operator = (const KafkaClientPool &) = delete;
	virtual ~KafkaClientPool()
	{
		if (nullptr != clients)
		{
			delete [] clients;
			clients = nullptr;
		}
	}
private:
	int poolsize;
	ClientType *clients;
	mutex lock;
};

#endif /* KAFKACLIENTPOOL_H_ */
