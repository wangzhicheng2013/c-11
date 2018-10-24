/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-10-21
Description:main entry for redis pub modern
ChangeLog:
			1. create this file
**************************************************/
#include "RedisPublisher.h"
RedisPublisher redisPublisher;
int main()
{
	RedisPublisher redisPublisher;
	if (!redisPublisher.Init())
	{
		return -1;
	}
	string channel = "AA";
	string message = "hello world";
	for (int i = 0;i < 1000;i++)
	{
		if (redisPublisher.Pub(channel, message))
		{
			cout << "pub to redis server ok" << endl;
		}
	}

	return 0;
}
