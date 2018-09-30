/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-09-30
Description:shape class
ChangeLog:
			1. create this file
**************************************************/

#ifndef SHAPE_H_
#define SHAPE_H_
#include "Pointer.h"
enum ShapeType
{
	SQUARE,
	RECTANGLE,
	UNKNOWN
};
class Shape
{
public:
	Shape();
	/*
	 * @purpose:get shape type
	 * */
	virtual ShapeType GetShapeType() = 0;
	virtual ~Shape();
};

#endif /* SHAPE_H_ */
