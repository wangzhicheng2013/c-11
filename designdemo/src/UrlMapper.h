/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-10-01
Description:url mapper class
ChangeLog:
			1. create this file
**************************************************/

#ifndef URLMAPPER_H_
#define URLMAPPER_H_
#include <string>
#include <unordered_map>
using namespace std;
enum UrlType
{
	PRODUCT,
	DEVICE,
	SUBSCRIPTION,
	LOGLEVEL,
	UNKNOWNURLTYPE
};
class UrlMapper
{
public:
	UrlMapper();
	/*
	 * @purpose:get url type
	 * */
	UrlType GetType(const string &url);
	virtual ~UrlMapper();
private:
	unordered_map<string, UrlType>mapper;
};

#endif /* URLMAPPER_H_ */
