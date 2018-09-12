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
#include <string>
#include <vector>
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
	virtual ~KafkaProducerClient();
private:
	unique_ptr<Conf>ConfPtr;
	unique_ptr<Producer>ProducerPtr;
	ProducerDeliveryReportCallBack producerDeliveryReportCallBack;
	string topic;
	int partition;
	int timeout;

};

#endif /* KAFKAPRODUCERCLIENT_H_ */
