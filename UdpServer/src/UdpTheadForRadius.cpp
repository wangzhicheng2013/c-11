/*
 * UdpTheadForRadius.cpp
 *
 *  Created on: 2019-3-13
 *      Author: root
 */

#include "UdpTheadForRadius.h"

UdpTheadForRadius::UdpTheadForRadius()
{
	// TODO Auto-generated constructor stub
}
bool UdpTheadForRadius::DealUdpMessage(int fd)
{
	char buf[buffer_size] = "";
	socklen_t size = sizeof(struct sockaddr);
	struct sockaddr_in client_addr = {0};
	int len = recvfrom(fd, buf, sizeof(buf), 0, (struct sockaddr *)&client_addr, &size);
	if (len < 0)
	{
		cerr << "server recv message error...!" << endl;
		return false;
	}
	if (0 == len)
	{
		cerr << "connection closed...!" << endl;
	}
	cout << "server recv message len = " << len << endl;
	cout << "sever send back message now...!" << endl;
	sendto(fd, buf, sizeof(buf), 0, (struct sockaddr *)&client_addr, size);
	return true;
}
UdpTheadForRadius::~UdpTheadForRadius()
{
	// TODO Auto-generated destructor stub
}
