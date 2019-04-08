/*
 * PingRes.cpp
 *
 *  Created on: 2019-4-8
 *      Author: root
 */

#include "PingRes.h"

PingRes::PingRes()
{
	// TODO Auto-generated constructor stub
	ping_path = nullptr;
	pack_num = 0;
	send_num = 0;
	recv_num = 0;
	loss_rate = 0;
}
void PingRes::ShowRes()
{
	cout << "send number = " << send_num << endl;
	cout << "receive number = " << recv_num << endl;
	cout << "packet loss rate = " << loss_rate << endl;
}
PingRes::~PingRes()
{
	// TODO Auto-generated destructor stub
}
