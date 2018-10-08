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

#include "HttpConfig.h"

HttpConfig::HttpConfig()
{
	// TODO Auto-generated constructor stub
	url_port = 0;
	response_code = 0;
}
/*
 * @purpose:show the members
 * */
void HttpConfig::Show()
{
	cout << "url = " << url << endl;
	cout << "url_ip = " << url_ip << endl;
	cout << "url_port = " << url_port << endl;
	cout << "url_path = " << url_path << endl;
}
HttpConfig::~HttpConfig()
{
	// TODO Auto-generated destructor stub
}
