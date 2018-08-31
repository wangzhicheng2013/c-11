/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-08-30
Description:thread pool
ChangeLog:
			1. create this file
 **************************************************/

#include "ThreadPool.h"

ThreadPool::ThreadPool()
{
}
/*
 * @purpose:init thread pool
 * */
bool ThreadPool::Init(int threadnum)
{
	if (threadnum <= 0 || threadnum > MAXTHREADNUM)
	{
		return false;
	}
	threadvec.resize(threadnum);
	try
	{
		for (int i = 0;i < threadnum;i++)
		{
			threadvec[i] = thread(bind(&ThreadPool::RunTaskFromList, this));
		}
	}
	catch (...)
	{
		return false;
	}
	return true;
}
/*
 * @purpose:get task from list and run it
 * */
void ThreadPool::RunTaskFromList()
{
	while (true)
	{
		unique_lock<mutex>lk(lock_for_pool);
		cond_for_pool.wait(lk, [this] {return !tasklist.empty();});
		auto task = tasklist.front();
		tasklist.pop_front();
		lk.unlock();
		if (task != nullptr)
		{
			task->Run();
			delete task;
			task = nullptr;
		}
	}
}
/*
 * @purpose:add task into thread pool
 * */
void ThreadPool::AddTask(Task *task)
{
	if (nullptr == task)
	{
		return;
	}
	lock_guard<mutex>lk(lock_for_pool);
	tasklist.push_back(task);
	cond_for_pool.notify_all();
}
ThreadPool::~ThreadPool()
{
	for (auto &it : threadvec)
	{
		if (it.joinable())
		{
			it.join();
		}
	}
}
