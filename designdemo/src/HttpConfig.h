/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-10-02
Description:http config class
ChangeLog:
			1.create this file
			2.update constructor to add default value
**************************************************/

#ifndef HTTPCONFIG_H_
#define HTTPCONFIG_H_
#include <string>
#include "HttpKey.h"
using namespace std;
class HttpConfig
{
public:
	HttpConfig();
	virtual ~HttpConfig();
public:
	string url;
	RestType rest_type;
	UrlType url_type;
	string request_body;
	string response_body;
	long response_code;
};

#endif /* HTTPCONFIG_H_ */
