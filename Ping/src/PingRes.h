/*
 * PingRes.h
 *
 *  Created on: 2019-4-8
 *      Author: root
 */

#ifndef PINGRES_H_
#define PINGRES_H_
#include <iostream>
using namespace std;
class PingRes
{
public:
	PingRes();
	virtual ~PingRes();
public:
	void ShowRes();
public:
	const char *ping_path;
	int pack_num;
	int send_num;
	int recv_num;
	int loss_rate;
};

#endif /* PINGRES_H_ */
