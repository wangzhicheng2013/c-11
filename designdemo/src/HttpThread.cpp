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

#include "HttpThread.h"

HttpThread::HttpThread()
{
	// TODO Auto-generated constructor stub
	pEventBase = nullptr;
	pEventHttp = nullptr;
	pSSLCtx = nullptr;
	sock_fd = -1;
}
HttpThread::HttpThread(const HttpThread &httpThread)
{
	pEventBase = httpThread.pEventBase;
	pEventHttp = httpThread.pEventHttp;
	sock_fd = httpThread.sock_fd;
}
HttpThread & HttpThread::operator = (const HttpThread &httpThread)
{
	pEventBase = httpThread.pEventBase;
	pEventHttp = httpThread.pEventHttp;
	sock_fd = httpThread.sock_fd;
	return *this;
}
/*
 * @purpose:init http thread
 * @return true if init ok
 * */
bool HttpThread::Init(int fd)
{
	sock_fd = fd;
	if (sock_fd < 0)
	{
		cerr << sock_fd << " is invalid...!" << endl;
		return false;
	}
	pEventBase = event_base_new();
	if (nullptr == pEventBase)
	{
		cerr << "event base is null...!" << endl;
		return false;
	}
	pEventHttp = evhttp_new(pEventBase);
	if (nullptr == pEventHttp)
	{
		cerr << "event http is null...!" << endl;
		return false;
	}
	if (evhttp_accept_socket(pEventHttp, sock_fd))
	{
		cerr << "http accept on sock = " << sock_fd << " failed...!" << endl;
		return false;
	}
	evhttp_set_gencb(pEventHttp, &HttpThread::HttpCallBackFun, NULL);
	/*if (!InitHttps())
	{
		return false;
	}*/
	return true;
}
/*
 * @purpose:init https
 * @return true if init ok
 * */
bool HttpThread::InitHttps()
{
	SSL_library_init();
	OpenSSL_add_all_algorithms();
	SSL_load_error_strings();
	pSSLCtx = SSL_CTX_new(SSLv23_server_method());
	if (nullptr == pSSLCtx)
	{
		cerr << "SSL_CTX_new(SSLv32_server_method() failed...!" << endl;
		return false;
	}
	SSL_CTX_set_options(pSSLCtx, SSL_OP_SINGLE_DH_USE |
			SSL_OP_SINGLE_ECDH_USE |
			SSL_OP_NO_SSLv2);
	EC_KEY *ecdh = EC_KEY_new_by_curve_name(NID_X9_62_prime256v1);
	if (nullptr == ecdh)
	{
		cerr << "EC_KEY_new_by_curve_name(NID_X9_62_prime256v1) failed...!" << endl;
		return false;
	}
	if (1 != SSL_CTX_set_tmp_ecdh(pSSLCtx, ecdh))
	{
		cerr << "SSL_CTX_set_tmp_ecdh failed...!" << endl;
		return false;
	}
	SetupCerts();
	evhttp_set_bevcb(pEventHttp, &HttpThread::HttpsCallBackFun, pSSLCtx);
	return true;
}
/*
 * @purpose:http dispatch event
 * */
void HttpThread::HttpDispathEvent()
{
	if (pEventBase != nullptr)
	{
		event_base_dispatch(pEventBase);
	}
}
/*
 * @purpose:http call back function
 * */
void HttpThread::HttpCallBackFun(struct evhttp_request *req, void *arg)
{
	HttpUtility httpUtility(req);
	httpUtility.HandleHttp();
}
/*
 * @purpose:This callback is responsible for creating a new SSL connection
 * 		and wrapping it in an OpenSSL bufferevent
 * */
struct bufferevent *HttpThread::HttpsCallBackFun(struct event_base *base, void *arg)
{
	SSL_CTX *ctx = (SSL_CTX *)arg;
	struct bufferevent *r = bufferevent_openssl_socket_new(base,
			-1,
			SSL_new(ctx),
			BUFFEREVENT_SSL_ACCEPTING,
			BEV_OPT_CLOSE_ON_FREE);
	return r;
}
/*
 * @purpose:set up certificate
 * */
void HttpThread::SetupCerts()
{
	if (1 != SSL_CTX_use_certificate_chain_file(pSSLCtx, certificate_chain))
	{
		cerr << "SSL_CTX_use_certificate_chain_file = " << certificate_chain << " failed...!" << endl;
		exit(EXIT_FAILURE);
	}
	if (1 != SSL_CTX_use_PrivateKey_file(pSSLCtx, private_key, SSL_FILETYPE_PEM))
	{
		cerr << "SSL_CTX_use_PrivateKey_file = " << private_key << " failed...!" << endl;
		exit(EXIT_FAILURE);
	}
	if (1 != SSL_CTX_check_private_key(pSSLCtx))
	{
		cerr << "SSL_CTX_check_private_key = " << private_key << " failed...!" << endl;
		exit(EXIT_FAILURE);
	}
}
HttpThread::~HttpThread()
{
	// TODO Auto-generated destructor stub
	if (nullptr != pEventBase)
	{
		event_base_loopexit(pEventBase, NULL);
	}
	if (nullptr != pEventHttp)
	{
		evhttp_free(pEventHttp);
		pEventHttp = nullptr;
	}
	if (nullptr != pEventBase)
	{
		event_base_free(pEventBase);
		pEventBase = nullptr;
	}
}
