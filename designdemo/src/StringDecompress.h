/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-10-15
Description:string decompress
ChangeLog:
			1.create this file
			2.update ReadCompressData method
			3.refactor ReadCompressData method
			4.add CheckCompressData method
 **************************************************/

#ifndef STRINGDECOMPRESS_H_
#define STRINGDECOMPRESS_H_
#include <ctype.h>
#include <iostream>
#include <string>
#include <set>
#include <stdexcept>
using namespace std;
class StringUnit
{
public:
	StringUnit();
	StringUnit(const string &, const string &);

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
	StringDecompress(string &);
	/*
	 * @purpose:check compress data
	 * @return true if check ok
	 * */
	bool CheckCompressData(string &);
	/*
	 * @purpose:read compress data into depressdata
	 * */
	void ReadCompressData(const string &);
	/*
	 * @purpose:judge character validity
	 * */
	inline bool ChIsValid(char ch)
	{
		return isdigit(ch) || isupper(ch) || islower(ch);
	}
	/*
	 * @purpose:get depress string
	 * */
	void GetDepressString(string &);
	virtual ~StringDecompress();
private:
	multiset<StringUnit, DepressDataCmp>depressdata;
};

#endif /* STRINGDECOMPRESS_H_ */
