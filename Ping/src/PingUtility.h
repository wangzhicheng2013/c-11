/*
 * PingUtility.h
 *
 *  Created on: 2019-4-8
 *      Author: root
 */

#ifndef PINGUTILITY_H_
#define PINGUTILITY_H_
#include "CommonDefine.h"
#include "PingRes.h"
class PingUtility {
public:
	static PingUtility &GetInstance()
	{
		return pingUtility;
	}
	bool Init();
	void Ping(PingRes &pingRes);
private:
	unsigned short CheckSum(unsigned short *addr, int len);
	float TimeDiff(struct timeval *begin, struct timeval *end);
	void Pack(struct icmp *icmp, int sequence);
	int UnPack(char *buf, int len, char *addr);
	void GetDestAddr(struct sockaddr_in &to, PingRes &pingRes);
private:
	unsigned short pid;
	char buf[BUF_SIZE];
	int sockfd;
private:
	PingUtility();
	virtual ~PingUtility();
private:
	static PingUtility pingUtility;
};

#endif /* PINGUTILITY_H_ */
