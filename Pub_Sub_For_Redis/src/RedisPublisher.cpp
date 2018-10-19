/*
 * RedisPublisher.cpp
 *
 *  Created on: 2018-10-19
 *      Author: root
 */

#include "RedisPublisher.h"

RedisPublisher::RedisPublisher() {
	// TODO Auto-generated constructor stub
	pBase = nullptr;
	pCtx = nullptr;

}
/*
 * @purpose:call back function for connection of redis
 * */
void RedisPublisher::ConnectCallBack(const redisAsynContext *context, int status)
{
	if (REDIS_OK != status)
	{
		cout << context->errstr;
	}
	else
	{
		cout << "redis connect ok" << endl;
	}
}
/*
 * @purpose:call back function for disconnection of redis
 * */
void RedisPublisher::DisconnectCallBack(const redisAsynContext *context, int status)
{
	if (REDIS_OK != status)
	{
		cout << context->errstr;
	}
	else
	{
		cout << "redis disconnect ok" << endl;
	}
}
RedisPublisher::~RedisPublisher() {
	// TODO Auto-generated destructor stub
}
