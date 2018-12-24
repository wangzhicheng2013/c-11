/*
 * DispatchGetKeyOfPoa.h
 *
 *  Created on: 2018-12-24
 *      Author: root
 */

#ifndef DISPATCHGETKEYOFPOA_H_
#define DISPATCHGETKEYOFPOA_H_
#include "GetKeyOfMqttPoa.h"
#include <unordered_map>
#include <memory>
class DispatchGetKeyOfPoa
{
public:
	static DispatchGetKeyOfPoa &GetInstance();
	int GetPartition(const char *poa);
private:
	void GetKey(const char *poa, string &key);
private:
	DispatchGetKeyOfPoa();
	virtual ~DispatchGetKeyOfPoa();
private:
	unordered_map<string, unique_ptr<GetKeyOfPoa> >mapper;
private:
	static DispatchGetKeyOfPoa obj;
	const string MQTT = "mqtt";

};

#endif /* DISPATCHGETKEYOFPOA_H_ */
