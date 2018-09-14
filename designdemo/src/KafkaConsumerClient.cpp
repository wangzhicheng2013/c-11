/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-09-12
Description:kafka consumer client
ChangeLog:
			1. create this file
 **************************************************/

#include "KafkaConsumerClient.h"
void ConsumerRebalanceCallBack::rebalance_cb(KafkaConsumer *consumer,
			ErrorCode ret,
			vector<TopicPartition *>&partition)
{
	if (ERR__ASSIGN_PARTITIONS == ret)
	{
		consumer->assign(partition);
		return;
	}
	consumer->unassign();
}
KafkaConsumerClient::KafkaConsumerClient()
{
	// TODO Auto-generated constructor stub
}
/*
 * @purpose:init client
 * @return true if init ok
 * */
bool KafkaConsumerClient::Init(KafkaClientConfig &_config)
{
	string errstr;
	config = _config;
	ConfPtr = unique_ptr<Conf>(Conf::create(RdKafka::Conf::CONF_GLOBAL));
	if (nullptr == ConfPtr)
	{
		return false;
	}
	if (Conf::CONF_OK != ConfPtr->set("rebalance_cb", &consumerRebalanceCallBack, errstr))
	{
		cout << errstr << endl;
		return false;
	}
	if (Conf::CONF_OK != ConfPtr->set("group.id", config.group, errstr))
	{
		cout << errstr << endl;
		return false;
	}
	for (auto &it : config.confs)
	{
		if (Conf::CONF_OK != ConfPtr->set(it.first, it.second, errstr))
		{
			cout << errstr << endl;
			return false;
		}
	}
	ConsumerPtr = unique_ptr<KafkaConsumer>(KafkaConsumer::create(ConfPtr.get(), errstr));
	if (nullptr == ConsumerPtr)
	{
		cout << errstr << endl;
		return false;
	}
	ErrorCode ret = ConsumerPtr->subscribe(config.topics);
	cout << "ret = " << ret << endl;
	cout << "config.topics = " << config.topics[0] << endl;
	return ERR_NO_ERROR == ret;
}
/*
 * @purpose:Pop message from kafka
 * @return true if pop ok
 * */
bool KafkaConsumerClient::Pop(string &msg)
{
	char *start = nullptr;
	size_t len = 0;
	unique_ptr<Message>MsgPtr(ConsumerPtr->consume(config.timeout));
	if (nullptr == MsgPtr)
	{
		return false;
	}
	bool succ = false;
	switch (MsgPtr->err())
	{
	case ERR_NO_ERROR:
		start = static_cast<char *>(MsgPtr->payload());
		len = MsgPtr->len();
		if (nullptr != start && len > 0)
		{
			msg.assign(start, len);
			succ = true;
		}
		break;
	default:
		break;
	}
	return succ;
}
KafkaConsumerClient::~KafkaConsumerClient()
{
	// TODO Auto-generated destructor stub
	if (nullptr != ConsumerPtr)
	{
		ConsumerPtr->close();
		ConsumerPtr = nullptr;
	}
	wait_destroyed(5000);
}
