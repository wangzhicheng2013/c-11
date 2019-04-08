/*
 * PingUtility.cpp
 *
 *  Created on: 2019-4-8
 *      Author: root
 */

#include "PingUtility.h"
PingUtility PingUtility::pingUtility;
PingUtility::PingUtility() {
	// TODO Auto-generated constructor stub
}
void PingUtility::Ping(PingRes &pingRes)
{
}
unsigned short PingUtility::CheckSum(unsigned short *addr, int len)
{
    unsigned int sum = 0;
    while (len > 1)
    {
        sum += *addr++;
        len -= 2;
    }
    if (1 == len)
    {
        sum += *(reinterpret_cast<unsigned char *>(addr));
    }
    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    return static_cast<unsigned short>(~sum);
}
PingUtility::~PingUtility() {
	// TODO Auto-generated destructor stub
}
