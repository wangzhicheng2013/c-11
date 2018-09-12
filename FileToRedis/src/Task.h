/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-08-30
Description:task absolute class
ChangeLog:
			1. create this file
 **************************************************/

#ifndef TASK_H_
#define TASK_H_
class Task
{
public:
	/*
	 * @purpose:task run entity
	 * */
	virtual void Run() = 0;
	virtual ~Task()
	{
	}
};

#endif /* TASK_H_ */
