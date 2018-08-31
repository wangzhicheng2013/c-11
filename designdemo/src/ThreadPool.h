/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-08-30
Description:thread pool
ChangeLog:
			1. create this file
 **************************************************/

#ifndef THREADPOOL_H_
#define THREADPOOL_H_
#include "Task.h"
#include <vector>
#include <list>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;
static const int MAXTHREADNUM = 128;
class ThreadPool
{
public:
	ThreadPool();
	ThreadPool(const ThreadPool &) = delete;
	ThreadPool & operator = (const ThreadPool &) = delete;
	/*
	 * @purpose:init thread pool
	 * */
	bool Init(int);
	/*
	 * @purpose:add task into thread pool
	 * */
	void AddTask(Task *);
	virtual ~ThreadPool();
private:
	/*
	 * @purpose:get task from list and run it
	 * */
	void RunTaskFromList();
private:
	mutex lock_for_pool;
	condition_variable cond_for_pool;
	list<Task *>tasklist;
	vector<thread>threadvec;
};

#endif /* THREADPOOL_H_ */
