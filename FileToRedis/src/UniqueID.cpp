/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-09-10
Description:generate unique id
ChangeLog:
			1. create this file

#include "UniqueID.h"

UniqueID::UniqueID()
{
	// TODO Auto-generated constructor stub

}
/*
 * @purpose:generate a uuid
 * */
void UniqueID::UUID(string &uuid)
{
	uuid_t id;
	char buf[256] = "";
	uuid_generate(id);
	uuid2string(id, buf);
	uuid = buf;
}
UniqueID::~UniqueID()
{
	// TODO Auto-generated destructor stub
}
