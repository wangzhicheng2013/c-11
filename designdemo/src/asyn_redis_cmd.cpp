#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <ctype.h>
#include <pthread.h>
#include <iostream>
#include <memory>
#include <functional>
#include <openssl/ssl.h>
#include <openssl/err.h>

#include <event2/bufferevent.h>
#include <event2/bufferevent_ssl.h>
#include <event2/event.h>
#include <event2/http.h>
#include <event2/buffer.h>
#include <event2/util.h>
#include <event2/keyvalq_struct.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <hiredis/hiredis.h>
#include <hiredis/async.h>
#include <hiredis/adapters/libevent.h>
using namespace std;
//设置命令执行后的回调函数
void getCallback(redisAsyncContext *c, void *r, void *privdata) 
{
	redisReply *reply = (redisReply *)r;
	if (NULL == reply)
	{
		return;
	} 
	printf("argv[%s]: %s\n", (char*)privdata, reply->str);
	redisAsyncDisconnect(c);	// not disconnect redis 
	sleep(10);
}
//设置连接回调函数
void connectCallback(const redisAsyncContext *c, int status) 
{
	if (status != REDIS_OK) 
	{
		printf("Error: %s\n", c->errstr);
		return;
	}
	printf("Connected...\n");
}
//设置断开连接回调函数
void disconnectCallback(const redisAsyncContext *c, int status) 
{
	if (status != REDIS_OK) 
	{
		printf("Error: %s\n", c->errstr);
		return;
	}
	printf("Disconnected...\n");
}
int main()
{
	signal(SIGPIPE, SIG_IGN);	//捕捉程序收到数据包时候的信号
	struct event_base *base = event_base_new();
	redisAsyncContext *c = redisAsyncConnect("127.0.0.1", 6379);
	if (c->err) 
	{
		printf("Error: %s\n", c->errstr);
		return -1;
	}
	redisLibeventAttach(c, base);
	redisAsyncSetConnectCallback(c, connectCallback);
	redisAsyncSetDisconnectCallback(c, disconnectCallback);
	redisAsyncCommand(c, NULL, NULL, "SET 123 abc");
	redisAsyncCommand(c, getCallback, (char*)"end-1", "GET 123");
	event_base_dispatch(base);
	

	return 0;
}
