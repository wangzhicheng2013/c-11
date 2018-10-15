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

#include "StringDecompress.h"
StringUnit::StringUnit()
{
	repeated = 0;
}
StringUnit::StringUnit(const string &digit_str, const string &alpha_str)
{
	repeated = atoi(digit_str.c_str());
	str = alpha_str;
}
StringDecompress::StringDecompress(string &compress_str)
{
	// TODO Auto-generated constructor stub
	if (!CheckCompressData(compress_str))
	{
		throw logic_error("check compressed data failed...");
	}
	ReadCompressData(compress_str);
}
/*
 * @purpose:check compress data
 * @return true if check ok
 * */
bool StringDecompress::CheckCompressData(string &compress_str)
{
	if (compress_str.empty())
	{
		return false;
	}
	if (isdigit(compress_str[0]))
	{
		return false;
	}
	char ch;
	auto it = begin(compress_str);
	for (;it != end(compress_str);++it)
	{
		ch = *it;
		if (!ChIsValid(ch))
		{
			return false;
		}
	}
	--it;
	ch = *it;
	if (!isdigit(ch))
	{
		compress_str += "1";
	}
	return true;
}
/*
 * @purpose:read compress data into depressdata
 * */
void StringDecompress::ReadCompressData(const string &compress_str)
{
	string alpha;
	string digit_str;
	bool digit_flag = false;
	char ch;
	char next_ch;
	for (auto it = begin(compress_str);it != end(compress_str);++it)
	{
		ch = *it;
		next_ch = *(it + 1);
		digit_flag = isdigit(ch);
		if (digit_flag)
		{
			digit_str += ch;
			if (!isdigit(next_ch))
			{
				depressdata.insert(StringUnit(digit_str, alpha));
				digit_str.clear();
				alpha.clear();
			}
			continue;
		}
		alpha += ch;
	}
}
/*
 * @purpose:get depress string
 * */
void StringDecompress::GetDepressString(string &depress_str)
{
	int repeated;
	depress_str.clear();
	for (auto &it : depressdata)
	{
		repeated = it.repeated;
		for (int i = 0;i < repeated;i++)
		{
			depress_str += it.str;
		}
	}
}
StringDecompress::~StringDecompress()
{
	// TODO Auto-generated destructor stub
}
