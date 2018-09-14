/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-09-14
Description:kafka client configuration
ChangeLog:
			1. create this file
**************************************************/
#ifndef KAFKACLIENTCONFIG_H_
#define KAFKACLIENTCONFIG_H_
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class KafkaClientConfig
{
public:
	KafkaClientConfig();
	KafkaClientConfig(const KafkaClientConfig &);
	KafkaClientConfig & operator = (const KafkaClientConfig &);
	virtual ~KafkaClientConfig();
public:
	string topic;
	string group;
	int timeout;
	int partition;
	vector<pair<string, string> >confs;
	vector<string>topics;
};

#endif /* KAFKACLIENTCONFIG_H_ */
