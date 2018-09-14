/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-09-14
Description:kafka client configuration
ChangeLog:
			1. create this file
**************************************************/

#include "KafkaClientConfig.h"

KafkaClientConfig::KafkaClientConfig()
{
	// TODO Auto-generated constructor stub
	timeout = 10;
	partition = -1;
}
KafkaClientConfig::KafkaClientConfig(const KafkaClientConfig &other)
{
	topic = other.topic;
	group = other.group;
	timeout = other.timeout;
	partition = other.partition;
	if (other.confs.size() > 0)
	{
		confs.resize(other.confs.size());
		copy(begin(other.confs), end(other.confs), begin(confs));
	}
	if (other.topics.size() > 0)
	{
		topics.resize(other.topics.size());
		copy(begin(other.topics), end(other.topics), begin(topics));
	}
}
KafkaClientConfig & KafkaClientConfig::operator = (const KafkaClientConfig &other)
{
	topic = other.topic;
	group = other.group;
	timeout = other.timeout;
	partition = other.partition;
	if (other.confs.size() > 0)
	{
		confs.resize(other.confs.size());
		copy(begin(other.confs), end(other.confs), begin(confs));
	}
	if (other.topics.size() > 0)
	{
		topics.resize(other.topics.size());
		copy(begin(other.topics), end(other.topics), begin(topics));
	}
	return *this;
}
KafkaClientConfig::~KafkaClientConfig()
{
	// TODO Auto-generated destructor stub
	timeout = 10;
	partition = -1;
}
