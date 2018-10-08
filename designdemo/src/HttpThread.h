/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-10-08
Description:http thread class
ChangeLog:
			1.create this file
			2.update Init method to add error output
			3.add https
**************************************************/

#ifndef HTTPTHREAD_H_
#define HTTPTHREAD_H_

#include "SockectUtility.h"
#include "HttpUtility.h"
class HttpThread
{
public:
	HttpThread();
	HttpThread(const HttpThread &);
	HttpThread & operator = (const HttpThread &);
	/*
	 * @purpose:init http thread
	 * @return true if init ok
	 * */
	bool Init(int);
	/*
	 * @purpose:http dispatch event
	 * */
	void HttpDispathEvent();
	virtual ~HttpThread();
private:
	/*
	 * @purpose:http call back function
	 * */
	static void HttpCallBackFun(struct evhttp_request *, void *);
	/*
	 * @purpose:This callback is responsible for creating a new SSL connection
	 * 		and wrapping it in an OpenSSL bufferevent
	 * */
	static struct bufferevent *HttpsCallBackFun(struct event_base *, void *);
	/*
	 * @purpose:set up certificate
	 * */
	void SetupCerts();
	/*
	 * @purpose:init https
	 * @return true if init ok
	 * */
	bool InitHttps();
private:
	event_base *pEventBase;
	evhttp *pEventHttp;
	SSL_CTX *pSSLCtx;
	int sock_fd;
	const char *certificate_chain = "./server-certificate-chain.pem";
	const char *private_key = "./server-private-key.pem";

};

#endif /* HTTPTHREAD_H_ */
