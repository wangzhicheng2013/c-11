/*
 * main.cpp
 *
 *  Created on: 2019-3-1
 *      Author: root
 */
#include "SimLog.h"
void Thread()
{
	string str(10, 'A');
	while (true)
	{
		for (int i = 0;i < 1024;i++)
		{
			SimLog::GetInstance().Log(str);
		}
		sleep(1);
	}
}
int main()
{
	if (false == SimLog::GetInstance().Init("./22.log"))
	{
		return -1;
	}
	thread th0(Thread);
	thread th1(Thread);
	th0.join();
	th1.join();
	return 0;
}
