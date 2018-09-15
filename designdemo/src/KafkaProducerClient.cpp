/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-09-15
Description:kafka producer client
ChangeLog:
			1. create this file
			2. add used
 **************************************************/

#include "KafkaProducerClient.h"
void ProducerDeliveryReportCallBack::dr_cb(Message &message)
{
}
KafkaProducerClient::KafkaProducerClient()
{
	// TODO Auto-generated constructor stub
	used = false;
}
/*
 * @purpose:init client
 * @return true if init ok
 * */
bool KafkaProducerClient::Init(const KafkaClientConfig &_config)
{
	string errstr;
	config = _config;
	ConfPtr = unique_ptr<Conf>(Conf::create(RdKafka::Conf::CONF_GLOBAL));
	if (nullptr == ConfPtr)
	{
		return false;
	}
	if (Conf::CONF_OK != ConfPtr->set("dr_cb", &producerDeliveryReportCallBack, errstr))
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
	ProducerPtr = unique_ptr<Producer>(Producer::create(ConfPtr.get(), errstr));
	if (nullptr == ProducerPtr)
	{
		cout << errstr << endl;
		return false;
	}
	if (-1 == config.partition)
	{
		config.partition = Topic::PARTITION_UA;
	}
	return true;
}
/*
 * @purpose:push message to kafka
 * @return true if push ok
 * */
bool KafkaProducerClient::Push(char *start, int size)
{
	if (nullptr == start || size <= 0)
	{
		return false;
	}
	ErrorCode ret = this->ProducerPtr->produce(config.topic,
			config.partition,
			Producer::RK_MSG_COPY,
			start,
			size,
			NULL,
			0,
			0,
			NULL);
	if (ERR_NO_ERROR != ret)
	{
		return false;
	}
	ProducerPtr->poll(config.timeout);
	return true;
}
KafkaProducerClient::~KafkaProducerClient()
{
	// TODO Auto-generated destructor stub
}
