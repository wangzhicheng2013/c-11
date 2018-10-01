/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-10-01
Description:http key class
ChangeLog:
			1. create this file
**************************************************/

#ifndef HTTPKEY_H_
#define HTTPKEY_H_
#include "UrlMapper.h"
enum RestType
{
	GET,
	POST,
	PUT,
	DELETE,
	UNKNOWNRESTTYPE
};
class HttpKey
{
public:
	explicit HttpKey(RestType, UrlType);
	virtual ~HttpKey();
public:
	RestType rest_type;
	UrlType url_type;
};
class HttpKeyCmp
{
public:
	inline bool operator () (const HttpKey &key0, const HttpKey &key1)
	{
		if (key0.rest_type !=  key1.rest_type)
		{
			return key0.rest_type < key1.rest_type;
		}
		return key0.url_type < key1.url_type;
	}
};
#endif /* HTTPKEY_H_ */
