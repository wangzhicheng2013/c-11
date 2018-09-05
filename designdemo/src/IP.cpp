/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-09-05
Description:ip address and its operation
ChangeLog:
			1. create this file
 **************************************************/

#include "IP.h"

IP::IP(unsigned char *_segs)
{
	// TODO Auto-generated constructor stub
	copy(_segs, _segs + 4, segs);
}
void IP::Show()
{
	cout << "IP = ";
	int last = SEGNUM - 1;
	for (int i = 0;i < SEGNUM;i++)
	{
		cout << static_cast<int>(segs[i]);
		if (i != last)
		{
			cout << ".";
		}
	}
	cout << endl;
}
ostream & operator <<(ostream &os, IP &ip)
{
	ip.Show();
	os << ip.address << endl;
	return os;
}
IP::~IP()
{
	// TODO Auto-generated destructor stub
}
