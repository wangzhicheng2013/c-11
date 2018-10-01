/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-10-01
Description:shape class
ChangeLog:
			1.create this file
			2.add ACCURACY_DEVIATION
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
static const double ACCURACY_DEVIATION = 1.0e-15;
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
