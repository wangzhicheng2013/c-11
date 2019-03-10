/*
 * SocketConfig.cpp
 *
 *  Created on: 2019-3-10
 *      Author: root
 */

#include "SocketConfig.h"

SocketConfig::SocketConfig()
{
	// TODO Auto-generated constructor stub
	port = 8080;
	backlog = 1024;
	type = UDP;
}

SocketConfig::~SocketConfig()
{
	// TODO Auto-generated destructor stub
}
