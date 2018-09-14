/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-09-14
Description:kafka consumer client
ChangeLog:
			1. create this file
 **************************************************/

#ifndef KAFKACONSUMERCLIENT_H_
#define KAFKACONSUMERCLIENT_H_
#include "rdkafkacpp.h"
#include "KafkaClientConfig.h"
#include <iostream>
#include <memory>
using namespace std;
using namespace RdKafka;
class ConsumerRebalanceCallBack : public RebalanceCb
{
private:
	void rebalance_cb(KafkaConsumer *consumer,
			ErrorCode ret,
			vector<TopicPartition *>&partition);
};
class KafkaConsumerClient
{
public:
	friend class ConsumerRebalanceCallBack;
	KafkaConsumerClient();
	/*
	 * @purpose:init client
	 * @return true if init ok
	 * */
	bool Init(const KafkaClientConfig &);
	/*
	 * @purpose:Pop message from kafka
	 * @return true if pop ok
	 * */
	bool Pop(string &msg);
	virtual ~KafkaConsumerClient();
public:
	KafkaClientConfig config;
private:
	unique_ptr<Conf>ConfPtr;
	unique_ptr<KafkaConsumer>ConsumerPtr;
	ConsumerRebalanceCallBack consumerRebalanceCallBack;
};

#endif /* KAFKACONSUMERCLIENT_H_ */
