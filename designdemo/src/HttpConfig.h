/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-10-08
Description:http config class
ChangeLog:
			1.create this file
			2.update constructor to add default value
			3.add ip port
			4.add Show method
**************************************************/

#ifndef HTTPCONFIG_H_
#define HTTPCONFIG_H_
#include <iostream>
#include <string>
#include "HttpKey.h"
using namespace std;
class HttpConfig
{
public:
	HttpConfig();
	/*
	 * @purpose:show the members
	 * */
	void Show();
	virtual ~HttpConfig();
public:
	string url;
	string url_ip;
	int url_port;
	string url_path;
	RestType rest_type;
	UrlType url_type;
	string request_body;
	string response_body;
	long response_code;
};

#endif /* HTTPCONFIG_H_ */
