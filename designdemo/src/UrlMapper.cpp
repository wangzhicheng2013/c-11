/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-10-01
Description:url mapper class
ChangeLog:
			1. create this file
**************************************************/

#include "UrlMapper.h"

UrlMapper::UrlMapper()
{
	// TODO Auto-generated constructor stub
	mapper.insert(make_pair("/product", PRODUCT));
	mapper.insert(make_pair("/device", DEVICE));
	mapper.insert(make_pair("/subscription", SUBSCRIPTION));
	mapper.insert(make_pair("/loglevel", LOGLEVEL));
}
/*
 * @purpose:get url type
 * */
UrlType UrlMapper::GetType(const string &url)
{
	string tmp;
	auto pos = url.find('?');
	if (pos != string::npos)
	{
		tmp.assign(url, 0, pos);
	}
	else
	{
		tmp = url;
	}
	auto it = mapper.find(tmp);
	if (end(mapper) == it)
	{
		return UNKNOWNURLTYPE;
	}
	return it->second;
}
UrlMapper::~UrlMapper()
{
	// TODO Auto-generated destructor stub
}
