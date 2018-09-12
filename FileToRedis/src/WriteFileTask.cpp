/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-09-10
Description:task for write file
ChangeLog:
			1. create this file
 **************************************************/

#include "WriteFileTask.h"

WriteFileTask::WriteFileTask()
{
	// TODO Auto-generated constructor stub

}
/*
 * @purpose:print to stdout
 * */
void WriteFileTask::Run()
{
	while (true)
	{
		string path = "/dev/shm/";
		string uuid;
		UniqueID::UUID(uuid);
		path += uuid;
		ofstream os(path);
		if (!os)
		{
			break;
		}
		char buf[1024] = "";
		for (int i = 0;i < 10000;i++)
		{
			UniqueID::UUID(uuid);
			snprintf(buf, sizeof(buf),
					"{\"serial\":\"%s\", \"poa\":\"mqtt://\"%s\"", uuid.c_str(), uuid.c_str());
		}
		os.close();
	}
}
WriteFileTask::~WriteFileTask()
{
	// TODO Auto-generated destructor stub
}
