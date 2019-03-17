/*
 * main.cpp
 *
 *  Created on: 2019-3-17
 *      Author: root
 */
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <thread>
#include "blockingconcurrentqueue.h"
#include "RedisClient.h"
#include "CpuBinding.h"
using namespace std;
using namespace moodycamel;
BlockingConcurrentQueue<string>queue;
static const int LOOP = 10000;
static const int THREADNUM = 4;
void MainTransaction(int cpu)
{
	CpuBinding::GetInstance().BindForThread(cpu);
	char buf[1024] = "";
	for (int loop = 0;loop < 100000;loop++)
	{
		for (int i = 0;i < sizeof(buf);i++)
		{
			buf[i] = 'A';
		}
		memset(buf, 0, sizeof(buf));
	}
}
void TestSetRedisWithBlockedStyle(int id)
{
	MainTransaction(id);
	string str(512, 'A');
	RedisClient redisclient;
	if (false == redisclient.Connect())
	{
		return;
	}
	char key[64] = "";
	for (int i = 0;i < LOOP;i++)
	{
		snprintf(key, sizeof(key), "PIDXXOOP%d%d", id, i);
		redisclient.SetValue(key, str);
		redisclient.DelValue(key);
	}
}
void TestSetRedisWithUnBlockedStyle(int id)
{
	CpuBinding::GetInstance().BindForThread(id);
	string str(512, 'A');
	RedisClient redisclient;
	if (false == redisclient.Connect())
	{
		return;
	}
	char key[64] = "";
	for (int i = 0;i < LOOP;i++)
	{
		snprintf(key, sizeof(key), "PIDXXOOP%d%d", id, i);
		redisclient.SetValue(key, str);
		redisclient.DelValue(key);
	}
}
int main()
{
	// 1.668s 1.013s for sys sys/total = 60.75%
/*	vector<thread>vec;
	vec.resize(THREADNUM);
	for (int i = 0;i < THREADNUM;i++)
	{
		vec[i] = thread(TestSetRedisWithBlockedStyle, i);
	}
	for (auto &it : vec)
	{
		it.join();
	}
*/
	// 1.534s 1.028s for sys sys/total = 67%
	vector<thread>vec0;
	vector<thread>vec1;
	vec0.resize(THREADNUM);
	vec1.resize(THREADNUM);
	for (int i = 0;i < THREADNUM;i++)
	{
		vec0[i] = thread(MainTransaction, i);
		vec1[i] = thread(TestSetRedisWithUnBlockedStyle, i);
	}
	for (auto &it : vec0)
	{
		it.join();
	}
	for (auto &it : vec1)
	{
		it.join();
	}
	return 0;
}
