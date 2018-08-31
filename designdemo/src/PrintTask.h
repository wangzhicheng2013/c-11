/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-08-30
Description:task for print
ChangeLog:
			1. create this file
 **************************************************/

#ifndef PRINTTASK_H_
#define PRINTTASK_H_
#include <iostream>
#include "Task.h"
using namespace std;
class PrintTask : public Task
{
public:
	PrintTask();
	/*
	 * @purpose:print to stdout
	 * */
	virtual void Run();
	virtual ~PrintTask();
};

#endif /* PRINTTASK_H_ */
