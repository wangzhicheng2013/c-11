/*
 * GetKeyOfMqttPoa.cpp
 *
 *  Created on: 2018-12-24
 *      Author: root
 */

#include "GetKeyOfMqttPoa.h"

GetKeyOfMqttPoa::GetKeyOfMqttPoa()
{
	// TODO Auto-generated constructor stub

}
/*
 * @purpose:get partition from poa
 * @return the partition
 *         -1 if get failed
 * */
int GetKeyOfMqttPoa::GetPartitionFromPoa(const char *poa)
{
	const char *p = strstr(poa, "mqtt-");
	if (nullptr == p)
	{
		return -1;
	}
	p += 5;
	if (0 == *p || 0 == *(p + 1))
	{
		return -1;
	}
	char buf[8] = "";
	strncpy(buf, p, 2);
	return atoi(buf);
}
GetKeyOfMqttPoa::~GetKeyOfMqttPoa()
{
	// TODO Auto-generated destructor stub
}
