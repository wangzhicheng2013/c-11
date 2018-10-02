/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-10-02
Description:http utility class
ChangeLog:
			1.create this file
			2.update ~HttpUtility() to add default value
**************************************************/

#include "HttpUtility.h"
map<HttpKey, ResponseHandler *, HttpKeyCmp>HttpUtility::mapper;
HttpUtility::HttpUtility()
{
	// TODO Auto-generated constructor stub
	http_req = nullptr;
}
HttpUtility::HttpUtility(struct evhttp_request *req) : http_req(req)
{
	if (nullptr == http_req)
	{
		return;
	}
	GetRestType();
	GetUrl();
	GetUrlType();
	GetRequestBody();
}
/*
 * @purpose:register handler
 * */
void HttpUtility::RegisterHandler(const HttpKey &key, ResponseHandler *handler)
{
	mapper.insert(make_pair(key, handler));
}
/*
 * @purpose:get rest type
 * */
void HttpUtility::GetRestType()
{
	switch (evhttp_request_get_command(http_req))
	{
	case EVHTTP_REQ_GET:
		config.rest_type =  GET;
		break;
	case EVHTTP_REQ_POST:
		config.rest_type =  POST;
		break;
	case EVHTTP_REQ_PUT:
		config.rest_type =  PUT;
		break;
	case EVHTTP_REQ_DELETE:
		config.rest_type =  DELETE;
		break;
	default:
		config.rest_type = UNKNOWNRESTTYPE;
	}
}
/*
 * @purpose:get url from http request
 * */
void HttpUtility::GetUrl()
{
	const char *p = evhttp_request_uri(http_req);
	if (p != nullptr)
	{
		config.url = p;
	}
}
/*
 * @purpose:get url type from http request
 * */
void HttpUtility::GetUrlType()
{
	config.url_type = urlMapper.GetType(config.url);
}
/*
 * @purpose:get body from http request
 * */
void HttpUtility::GetRequestBody()
{
	const char *body = (const char *)EVBUFFER_DATA(http_req->input_buffer);
	if (body != nullptr)
	{
		config.request_body = body;
	}
}
/*
 * @purpose:handle http request
 * */
void HttpUtility::HandleRequest()
{
	HttpKey httpKey(config.rest_type, config.url_type);
	auto it = mapper.find(httpKey);
	if (end(mapper) == it)
	{
		cerr << "find http key failed...!" << endl;
		return;
	}
	it->second->Handler(config);
}
/*
 * @purpose:reply to http client
 * */
void HttpUtility::ReplyClient()
{
	struct evbuffer *buf = evbuffer_new();
	evhttp_add_header(http_req->output_headers, "Content-Type", "application/json;charset=UTF-8");
	evbuffer_add_printf(buf, config.response_body.c_str());
	evhttp_send_reply(http_req, config.response_code, "return", buf);
	evbuffer_free(buf);
}
/*
 * @purpose:handle http request and send response to client
 * */
void HttpUtility::HandleHttp()
{
	HandleRequest();
	ReplyClient();
}
HttpUtility::~HttpUtility()
{
	// TODO Auto-generated destructor stub
	http_req = nullptr;
}
