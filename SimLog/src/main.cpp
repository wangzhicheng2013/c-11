/*
 * main.cpp
 *
 *  Created on: 2019-3-1
 *      Author: root
 */
#include "SimLog.h"
int main()
{
	if (false == SimLog::GetInstance().Init(""))
	{
		return -1;
	}
	string str(1024, 'A');
	for (int i = 0;i < 1000;i++)
	{
		SimLog::GetInstance().Log(str);
	}

	return 0;
}
