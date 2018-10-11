/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-10-11
Description:string operation set
ChangeLog:
			1. create this file
			2. add StringContain method
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
/*
 * @purpose:judge every character of small string is contained in the big string
 * @return true if it contains
 * */
bool StringOp::StringContain(const string &bigstr, const string &smallstr)
{
	static const int LEN = 256;
	bool HashArray[LEN] = {false};
	for (auto &ch : bigstr)
	{
		if (isupper(ch) || islower(ch))
		{
			HashArray[ch] = true;
		}
	}
	for (auto &ch : smallstr)
	{
		if (!isupper(ch) && !islower(ch))
		{
			return false;
		}
		if (!HashArray[ch])
		{
			return false;
		}
	}
	return true;
}
}
