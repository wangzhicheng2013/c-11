/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-09-10
Description:generate unique id
ChangeLog:
			1. create this file
 **************************************************/
#ifndef UNIQUEID_H_
#define UNIQUEID_H_
#include <uuid/uuid.h>
#include <string>
using namespace std;
class UniqueID
{
public:
	UniqueID() = delete;
	/*
	 * @purpose:generate a uuid
	 * */
	static void UUID(string &uuid);
	virtual ~UniqueID() = delete;
};

#endif /* UNIQUEID_H_ */
