/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-09-15
Description:program main entry
ChangeLog:
			1. create this file
			2.add kafka client test
			3.add KafkaClientPool test
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
		vec.push_back(MemoryBlock(25));
		vec.push_back(MemoryBlock(75));
	}
	catch (std::logic_error &err)
	{
		cerr << err.what() << endl;
	}
}
int main()
{
	TestStringBeads();
	TestIP();
/*	thread th0(TestKafkaProducerClient);
	thread th1(TestKafkaConsumerClient);
	th0.join();
	th1.join();*/
	TestMemoryBlock();
	return 0;
}
