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
void subCallback(redisAsyncContext *c, void *r, void *priv) 
{  
	redisReply *reply = (redisReply *)r;  
	if (NULL == reply)
	{
		return;  
	}
	if (reply->type == REDIS_REPLY_ARRAY && reply->elements == 3)
	{  
		cout << reply->element[0]->str << endl;
		if (strcmp(reply->element[0]->str, "subscribe" ) != 0 ) 
		{  
			printf("Received[%s] channel %s: %s\n",  
				(char*)priv,  
				reply->element[1]->str,  
				reply->element[2]->str);  
	        }  
	}  
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
	redisAsyncCommand(c, subCallback, (char*) "sub", "SUBSCRIBE foo");
	event_base_dispatch(base);

	return 0;
}
