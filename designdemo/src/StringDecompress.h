/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-10-11
Description:string decompress
ChangeLog:
			1. create this file
 **************************************************/

#ifndef STRINGDECOMPRESS_H_
#define STRINGDECOMPRESS_H_
#include <ctype.h>
#include <iostream>
#include <string>
#include <set>
using namespace std;
class StringUnit
{
public:
	StringUnit();

public:
	unsigned char repeated;
	string str;
};
class DepressDataCmp
{
public:
	bool operator () (const StringUnit &one, const StringUnit &two)
	{
		if (one.repeated != two.repeated)
		{
			return one.repeated < two.repeated;
		}
		return one.str < two.str;
	}
};
class StringDecompress
{
public:
	StringDecompress(const string &);
	/*
	 * @purpose:read compress data into depressdata
	 * */
	void ReadCompressData(const string &);
	virtual ~StringDecompress();
private:
	multiset<StringUnit>depressdata(DepressDataCmp);
};

#endif /* STRINGDECOMPRESS_H_ */
