/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-10-11
Description:string decompress
ChangeLog:
			1. create this file
 **************************************************/

#include "StringDecompress.h"
StringUnit::StringUnit()
{
	repeated = 0;
}
StringDecompress::StringDecompress(const string &compress_str)
{
	// TODO Auto-generated constructor stub

}
/*
 * @purpose:read compress data into depressdata
 * */
void StringDecompress::ReadCompressData(const string &compress_str)
{
	string::size_type len = compress_str.size();
	string alpha;
	string digit;
	for (string::size_type index = 0;index < len;++index)
	{
		if (isdigit(compress_str[index]))
		{
			digit += compress_str[index];
		}
		else
		{
			alpha += compress_str[index];
		}
		if (isdigit(compress_str[index]) && index + 1 < len && !isdigit(compress_str[index + 1]))
		{

		}
	}
}
StringDecompress::~StringDecompress()
{
	// TODO Auto-generated destructor stub
}
