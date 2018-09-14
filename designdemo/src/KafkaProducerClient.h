/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-09-12
Description:kafka producer client
ChangeLog:
			1. create this file
 **************************************************/
#ifndef KAFKAPRODUCERCLIENT_H_
#define KAFKAPRODUCERCLIENT_H_
#include "rdkafkacpp.h"
#include "KafkaClientConfig.h"
#include <iostream>
#include <memory>
using namespace std;
using namespace RdKafka;
class ProducerDeliveryReportCallBack : public DeliveryReportCb
{
private:
	void dr_cb(Message &);
};
class KafkaProducerClient
{
public:
	friend class ProducerDeliveryReportCallBack;
	KafkaProducerClient();
	/*
	 * @purpose:init client
	 * @return true if init ok
	 * */
	bool Init(const KafkaClientConfig &);
	/*
	 * @purpose:push message to kafka
	 * @return true if push ok
	 * */
	bool Push(char *start, int size);
	virtual ~KafkaProducerClient();
public:
	KafkaClientConfig config;
private:
	unique_ptr<Conf>ConfPtr;
	unique_ptr<Producer>ProducerPtr;
	ProducerDeliveryReportCallBack producerDeliveryReportCallBack;

};

#endif /* KAFKAPRODUCERCLIENT_H_ */
