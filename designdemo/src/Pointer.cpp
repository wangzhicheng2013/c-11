/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-09-29
Description:pointer class
ChangeLog:
			1. create this file
**************************************************/

#include "Pointer.h"

Pointer::Pointer(int x, int y) : x_coordinate(x), y_coordinate(y)
{
	// TODO Auto-generated constructor stub
}
Pointer::Pointer(const Pointer &other)
{
	x_coordinate = other.x_coordinate;
	y_coordinate = other.y_coordinate;
}
Pointer & Pointer::operator = (const Pointer &other)
{
	x_coordinate = other.x_coordinate;
	y_coordinate = other.y_coordinate;
	return *this;
}
/*
 * @purpose:compute distance between the two pointers
 * */
double Pointer::GetDistance(const Pointer &other)
{
	double diffX = pow(other.x_coordinate - x_coordinate, 2);
	double diffY = pow(other.y_coordinate - y_coordinate, 2);
	return sqrt(diffX + diffY);
}
Pointer::~Pointer()
{
	// TODO Auto-generated destructor stub
}
