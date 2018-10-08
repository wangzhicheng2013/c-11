/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-10-08
Description:http utility class
ChangeLog:
			1.create this file
			2.update ~HttpUtility() to add default value
			3.update GetUrl to decode url
			4.add https
**************************************************/

#ifndef HTTPUTILITY_H_
#define HTTPUTILITY_H_
#include <event.h>
#include <evhttp.h>
#include <event2/listener.h>
#include <event2/bufferevent_ssl.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#include "ResponseHandler.h"
#include "HttpConfig.h"
#include <iostream>
#include <map>

class HttpUtility
{
public:
	HttpUtility();
	HttpUtility(struct evhttp_request *);
	virtual ~HttpUtility();
	/*
	 * @purpose:register handler
	 * */
	static void RegisterHandler(const HttpKey &key, ResponseHandler *handler);
	/*
	 * @purpose:handle http request and send response to client
	 * */
	void HandleHttp();
private:
	/*
	 * @purpose:get rest type
	 * */
	void GetRestType();
	/*
	 * @purpose:get url from http request
	 * */
	void GetUrl();
	/*
	 * @purpose:get url type from http request
	 * */
	void GetUrlType();
	/*
	 * @purpose:get body from http request
	 * */
	void GetRequestBody();
	/*
	 * @purpose:handle http request
	 * */
	void HandleRequest();
	/*
	 * @purpose:reply to http client
	 * */
	void ReplyClient();
private:
	struct evhttp_request *http_req;
	HttpConfig config;
	static map<HttpKey, ResponseHandler *, HttpKeyCmp>mapper;
	UrlMapper urlMapper;

};

#endif /* HTTPUTILITY_H_ */
