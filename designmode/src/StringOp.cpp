/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-08-24
Description:string operation set
ChangeLog:
			1. create this file
 **************************************************/
#include "StringOp.h"
namespace stringop {
/*
 * @purpose:erase source string with delete string
 * */
void StringOp::Erase(string &sourcestr, const string &delstr)
{
	static const int CHARLEN = 256;
	bool hash[CHARLEN] = {false};
	for (auto &it : delstr)
	{
		hash[it] = true;
	}
	int index = 0;
	for (auto &it : sourcestr)
	{
		if (!hash[it])
		{
			sourcestr[index++] = it;
		}
	}
	sourcestr.assign(sourcestr, 0, index);
}
}
