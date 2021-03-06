/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-10-18
Description:program main entry
ChangeLog:
			1. create this file
			2.add kafka client test
			3.add KafkaClientPool test
			4.add redis client test
			5.add redis client pool test
			5.add Pointer test
			6.add Socket Utility test
			7.add ResponseHandlerInfo test
			8.add StringContaine test
			9.add StringDecompress test
**************************************************/

#include "MessageDispatch.h"
#include "ThreadPool.h"
#include "PrintTask.h"
#include "StringBeads.h"
#include "IP.h"
#include "KafkaProducerClient.h"
#include "KafkaConsumerClient.h"
#include "KafkaClientPool.h"
#include "MemoryBlock.h"
#include "RedisClient.h"
#include "RedisClientPool.h"
#include "Square.h"
#include "HttpServer.h"
#include "ResponseHandlerInfo.h"
#include "StringOp.h"
#include "StringDecompress.h"
#include <exception>
using namespace stringop;
int TestThreadPool()
{
	InputMsgHandler inputMsgHandler;
	OutputMsgHandler outputMsgHandler;
	MessageDispatch messageDispatch;
	messageDispatch.RegisterMsg(INPUTMSG, &inputMsgHandler);
	messageDispatch.RegisterMsg(OUTPUTMSG, &outputMsgHandler);
	messageDispatch.DispatchMsg(INPUTMSG);
	messageDispatch.DispatchMsg(OUTPUTMSG);
	ThreadPool threadpool;
	if (!threadpool.Init(2))
	{
		cerr << "thread pool init failed..." << endl;
		return -1;
	}
	for (int i = 0;i < 2;i++)
	{
		PrintTask *task = new PrintTask;
		threadpool.AddTask(task);
	}
	return 0;
}
void TestStringBeads()
{
	StringBeads stringBeads(2);
	vector<pair<int, Beads> >vec = {
			make_pair(1, (Beads){1}),
			make_pair(2, (Beads){1, 3, 4}),
			make_pair(3, (Beads){1, 3, 5})
	};
	stringBeads.Init(vec);
	cout << stringBeads.GetCountOfInValidColors() << endl;
}
void TestIP()
{
	unsigned char segs[SEGNUM] = {127, 0, 1, 1};
	IP ip(segs);
	ip.Show();
	cout << ip;
}
void TestKafkaProducerClient()
{
	KafkaClientPool<KafkaProducerClient>kafkaClientPool;
	KafkaClientConfig kafkaClientConfig;
	kafkaClientConfig.confs.emplace_back(make_pair("metadata.broker.list", "localhost:9092"));
	kafkaClientConfig.topic = "TOPIC0";
	if (!kafkaClientPool.Init(1, kafkaClientConfig))
	{
		cerr << "kafka client pool init failed...!" << endl;
		return;
	}
	KafkaProducerClient *kafkaProducerClient = kafkaClientPool.GetClient();
	if (nullptr == kafkaProducerClient)
	{
		cerr << "get kafka producer client failed...!" << endl;
		return;
	}
	char buf[64] = "123";
	for (int i = 0;i < 1000;i++)
	{
		cout << kafkaProducerClient->Push(buf, 3) << endl;
	}
	kafkaClientPool.FreeClient(kafkaProducerClient);
}
void TestKafkaConsumerClient()
{
	KafkaClientConfig kafkaClientConfig;
	kafkaClientConfig.confs.emplace_back(make_pair("metadata.broker.list", "localhost:9092"));
	kafkaClientConfig.topics.emplace_back("TOPIC0");
	kafkaClientConfig.group = "group01";
	kafkaClientConfig.timeout = 1000;
	KafkaConsumerClient kafkaConsumerClient;
	string msg;
	if (kafkaConsumerClient.Init(kafkaClientConfig))
	{
		while (1)
		{
			if (kafkaConsumerClient.Pop(msg))
			{
				cout << "msg = " << msg << endl;
			}
		}
	}
}
void TestMemoryBlock()
{
	vector<MemoryBlock>vec;
	try
	{
		/*vec.push_back(MemoryBlock(25));
		vec.push_back(MemoryBlock(75));
		strcpy(vec[0].data, "123");
		strcpy(vec[1].data, "4566");*/
		MemoryBlock mb(10);
		mb = MemoryBlock(25);
		strcpy(mb.data, "123");
	}
	catch (std::logic_error &err)
	{
		cerr << err.what() << endl;
	}
}
void TestRedisClient()
{
	RedisClient redisclient;
	if (!redisclient.Connect("localhost", 6379))
	{
		cerr << "redis server connect failed...!" << endl;
		return;
	}
	const char *key = "key00";
	string value = "value00";
	if (redisclient.SetValue(key, value))
	{
		cout << "set value to redis server ok." << endl;
	}
	value.clear();
	if (redisclient.GetValue(key, value))
	{
		cout << "get value from redis server ok." << endl;
		cout << value << endl;
	}
	if (redisclient.Publish(key, value.c_str()))
	{
		cout << "publish to redis server ok." << endl;
		cout << value << endl;
	}
	string value1;
	if (redisclient.Subscribe(key, value1))
	{
		cout << "subscribe from redis server ok." << endl;
		cout << value1 << endl;
	}
}
void PubThread()
{
	RedisClient redisclient;
	if (!redisclient.Connect("localhost", 6379))
	{
		cerr << "redis server connect failed...!" << endl;
		return;
	}
	const char *key = "key00";
	string value = "value00";
	while (1)
	{
		if (redisclient.Publish(key, value.c_str()))
		{
			cout << "publish to redis server ok." << endl;
			cout << value << endl;
		}
		sleep(2);
	}
}
void SubThread()
{
	RedisClient redisclient;
	if (!redisclient.Connect("localhost", 6379))
	{
		cerr << "redis server connect failed...!" << endl;
		return;
	}
	const char *key = "key00";
	string value;
	while (1)
	{
		if (redisclient.Subscribe(key, value))
		{
			cout << "subscribe from redis server ok." << endl;
			cout << value << endl;
		}
		sleep(2);
	}
}
RedisClientPool redisclientpool;
void RedisClientThread(const char *key, const string &value)
{
	auto ptr = redisclientpool.GetClient();
	if (nullptr == ptr)
	{
		cerr << "get redis client failed...!" << endl;
		return;
	}
	cout << "key = " << key << endl;
	string newvalue;
	if (ptr->SetValue(key, value))
	{
		cout << "set value to redis server ok." << endl;
	}
	if (ptr->GetValue(key, newvalue))
	{
		cout << "get value from redis server ok." << endl;
		cout << newvalue << endl;
	}
}
void TestRedisClientPool()
{
	RedisClientPoolConfig config;
	config.poolsize = 10;
	config.ip = "localhost";
	config.port = 6379;
	if (redisclientpool.InitPool(config))
	{
		cerr << "redis client pool init ok." << endl;
	}
	else
	{
		return;
	}
	char key[64] = "";
	string value;
	vector<string>keyVec;
	vector<string>valueVec;
	vector<thread>threadVec;
	for (size_t i = 0;i < config.poolsize;i++)
	{
		snprintf(key, sizeof(key), "key00%d", i);
		value = key;
		keyVec.emplace_back(key);
		valueVec.emplace_back(value);
	}
	for (size_t i = 0;i < config.poolsize;i++)
	{
		threadVec.emplace_back(thread(RedisClientThread, keyVec[i].c_str(), valueVec[i]));
	}
	for (auto &it : threadVec)
	{
		if (it.joinable())
		{
			it.join();
		}
	}
}
void TestPointer()
{
	Pointer p0(1, 2);
	Pointer p1(12, 21);
	cout << "distance = " << p0.GetDistance(p1) << endl;
}
void TestSquare()
{
	Pointer p0(0, 0);
	Pointer p1(0, 2);
	Pointer p2(2, 2);
	Pointer p3(2, 0);
	Square square;
	square.A = p0;
	square.B = p1;
	square.C = p2;
	square.D = p3;
	if (SQUARE == square.GetShapeType())
	{
		cout << "it is square." << endl;
	}
}
void TestSocketUtility()
{
	SocketConfig config;
	SockectUtility sockectUtility(config);
	if (sockectUtility.InitSocket())
	{
		cout << "socket init ok." << endl;
	}
	else
	{
		return;
	}
	if (sockectUtility.BindSocket())
	{
		cout << "socket bind ok." << endl;
	}
}
void TestUrlMapper()
{
	UrlMapper urlMapper;
	string url = "/device?XXX";
	if (DEVICE == urlMapper.GetType(url))
	{
		cout << "it is device url" << endl;
	}
}
void TestHttpServer()
{
	ResponseHandlerInfo responseHandlerInfo;
	responseHandlerInfo.Init();
	SocketConfig config;
	HttpServer httpServer(config);
	if (httpServer.Init(2))
	{
		cout << "http server init ok." << endl;
	}
}
void TestStringContain()
{
	string str0 = "AAAACDDSSDLLKKMMMMmmklAMMKNBFFRRaadsfvdsfdsghj";
	string str1 = "LLKKMMMMmmklMm";
	cout << StringOp::StringContain(str0, str1) << endl;
}
void TestStringDecompress()
{
	string str = "AA10BB2CKL100";
	string str1;
	try
	{
		StringDecompress stringDecompress(str);
		stringDecompress.GetDepressString(str1);
	}
	catch (exception &e)
	{
		cerr << e.what() << endl;
	}
	cout << "depress string = " << str1 << endl;
}
int main()
{
//	TestStringBeads();
	//TestIP();
/*	thread th0(TestKafkaProducerClient);
	thread th1(TestKafkaConsumerClient);
	th0.join();
	th1.join();*/
//	TestMemoryBlock();
//	TestRedisClient();
//	TestRedisClientPool();
//	TestPointer();
//	TestSquare();
//	TestSocketUtility();
//	TestUrlMapper();
//	TestHttpServer();
//	TestStringContain();
//	TestStringDecompress();
	thread pubthread(PubThread);
	thread subthread(SubThread);
	pubthread.join();
	subthread.join();
	return 0;
}
