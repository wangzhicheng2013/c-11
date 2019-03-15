/*
 * main.cpp
 *
 *  Created on: 2019-3-10
 *      Author: root
 */
#include "UdpServer.h"
int main()
{
	SocketConfig config;
	UdpServer server(config);
	cout << server.Init(2) << endl;

	return 0;
}
