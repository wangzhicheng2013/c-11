/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-09-07
Description:ip address and its operation
ChangeLog:
			1. create this file
			2. add new methods
 **************************************************/

#ifndef IP_H_
#define IP_H_
#include <string.h>
#include <iostream>
#include <string>
#include <ostream>
#include <algorithm>
using namespace std;
const static int SEGNUM = 4;
enum IPKIND
{
	A,
	B,
	C,
	D,
	E
};
class IP
{
public:
	IP(unsigned char *_segs);
	void Show();
	/*
	 * @purpose:identify ip kind
	 * */
	IPKIND WhatKind() const;
	friend ostream & operator << (ostream &, IP &);
	virtual ~IP();
private:
	union
	{
		unsigned char segs[SEGNUM];
		unsigned int address;
	};

};

#endif /* IP_H_ */
