/*
 * UdpTheadForRadius.h
 *
 *  Created on: 2019-3-13
 *      Author: root
 */

#ifndef UDPTHEADFORRADIUS_H_
#define UDPTHEADFORRADIUS_H_

#include "UdpThread.h"

class UdpTheadForRadius: public UdpThread {
public:
	UdpTheadForRadius();
	virtual ~UdpTheadForRadius();
public:
	virtual bool DealUdpMessage(int fd);
};

#endif /* UDPTHEADFORRADIUS_H_ */
