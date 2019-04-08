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
	PingUtility &GetInstance()
	{
		return pingUtility;
	}
	void Ping(PingRes &pingRes);
private:
	unsigned short CheckSum(unsigned short *addr, int len);
private:
	PingUtility();
	virtual ~PingUtility();
private:
	static PingUtility pingUtility;
};

#endif /* PINGUTILITY_H_ */
