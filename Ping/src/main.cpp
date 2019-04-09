/*
 * main.cpp
 *
 *  Created on: 2019-4-8
 *      Author: root
 */
#include "PingUtility.h"
int main()
{
	PingRes pingRes;
	pingRes.ping_path = "www.baidu.com";
	pingRes.pack_num = 5;
	PingUtility::GetInstance().Ping(pingRes);
	pingRes.ShowRes();

	return 0;
}
