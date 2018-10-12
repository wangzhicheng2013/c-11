/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-10-12
Description:string decompress
ChangeLog:
			1.create this file
			2.update ReadCompressData method
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
	string digit_str;
	bool digit_flag = false;
	char ch;
	for (string::size_type index = 0;index < len;++index)
	{
		ch = compress_str[index];
		digit_flag = isdigit(ch);
		if (digit_flag)
		{
			digit_str += ch;
			if (!isdigit(compress_str[index + 1]))
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
StringDecompress::~StringDecompress()
{
	// TODO Auto-generated destructor stub
}
