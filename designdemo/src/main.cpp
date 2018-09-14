/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-09-14
Description:program main entry
ChangeLog:
			1. create this file
			2.add kafka client test
**************************************************/

#include "MessageDispatch.h"
#include "ThreadPool.h"
#include "PrintTask.h"
#include "StringBeads.h"
#include "IP.h"
#include "KafkaProducerClient.h"
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
	KafkaClientConfig kafkaClientConfig;
	kafkaClientConfig.confs.emplace_back(make_pair("metadata.broker.list", "localhost:9092"));
	kafkaClientConfig.topic = "TOPIC0";
	KafkaProducerClient kafkaProducerClient;
	char buf[64] = "123";
	if (kafkaProducerClient.Init(kafkaClientConfig))
	{
		cout << kafkaProducerClient.Push(buf, 3) << endl;
	}
}
int main()
{
	TestStringBeads();
	TestIP();
	TestKafkaProducerClient();

	return 0;
}
