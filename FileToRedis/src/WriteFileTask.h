/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-09-10
Description:task for write file
ChangeLog:
			1. create this file
 **************************************************/

#ifndef WRITEFILETASK_H_
#define WRITEFILETASK_H_
#include <fstream>
#include "Task.h"
#include "UniqueID.h"
using namespace std;
class WriteFileTask : public Task
{
public:
	WriteFileTask();
	/*
	 * @purpose:print to stdout
	 * */
	virtual void Run();
	virtual ~WriteFileTask();
};

#endif /* WriteFileTask_H_ */
