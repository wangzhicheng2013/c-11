/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-10-24
Description:main entry for redis sub modern
ChangeLog:
			1. create this file
**************************************************/
#include "RedisSubscriber.h"
void RecieveMessage(const char *channel_name,
		const char *message,
		int len)
{
	if (nullptr == channel_name || nullptr == message)
	{
		return;
	}
	string str(message, len);
	cout << "Recieve message = " << str << " from channel = " << channel_name << endl;
}
int main()
{
	SubCallBackFun subCallBackFun = SubCallBackFun([](const char *channel_name,
			const char *message,
			int len){
		string str(message, len);
		cout << "Recieve message = " << str << " from channel = " << channel_name << endl;

	});
	RedisSubscriber redisSubscriber(subCallBackFun);
	if (!redisSubscriber.Init())
	{
		return -1;
	}
	string channel = "AA";
	while (true)
	{
		if (redisSubscriber.Sub(channel))
		{
			cout << "pub to redis server ok" << endl;
		}
		sleep(1);
	}
	return 0;
}
