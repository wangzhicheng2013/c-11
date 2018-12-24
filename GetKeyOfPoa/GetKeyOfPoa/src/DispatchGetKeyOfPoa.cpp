/*
 * DispatchGetKeyOfPoa.cpp
 *
 *  Created on: 2018-12-24
 *      Author: root
 */

#include "DispatchGetKeyOfPoa.h"
DispatchGetKeyOfPoa DispatchGetKeyOfPoa::obj;
DispatchGetKeyOfPoa::DispatchGetKeyOfPoa()
{
	// TODO Auto-generated constructor stub
	mapper["mqtt"] = unique_ptr<GetKeyOfPoa>(new GetKeyOfMqttPoa);
}
DispatchGetKeyOfPoa &DispatchGetKeyOfPoa::GetInstance()
{
	return obj;
}
void DispatchGetKeyOfPoa::GetKey(const char *poa, string &key)
{
	if (strstr(poa, "mqtt"))
	{
		key = MQTT;
	}
}
int DispatchGetKeyOfPoa::GetPartition(const char *poa)
{
	string key;
	GetKey(poa, key);
	auto it = mapper.find(key);
	if (end(mapper) == it)
	{
		return -1;
	}
	return it->second->GetPartitionFromPoa(poa);
}
DispatchGetKeyOfPoa::~DispatchGetKeyOfPoa()
{
	// TODO Auto-generated destructor stub
}
