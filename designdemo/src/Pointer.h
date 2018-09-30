/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-09-29
Description:pointer class
ChangeLog:
			1. create this file
**************************************************/

#ifndef POINTER_H_
#define POINTER_H_
#include <math.h>
class Pointer
{
public:
	Pointer();
	Pointer(int, int);
	Pointer(const Pointer &);
	Pointer & operator = (const Pointer &);
	/*
	 * @purpose:compute distance between the two pointers
	 * */
	double GetDistance(const Pointer &);
	virtual ~Pointer();
public:
	int x_coordinate;
	int y_coordinate;
};

#endif /* POINTER_H_ */
