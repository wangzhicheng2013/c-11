/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-09-30
Description:square class
ChangeLog:
			1. create this file
**************************************************/

#ifndef SQUARE_H_
#define SQUARE_H_

#include "Shape.h"

class Square: public Shape
{
public:
	Square();
	/*
	 * @purpose:get shape type
	 * */
	virtual ShapeType GetShapeType() override;
	virtual ~Square();
public:
	Pointer A;
	Pointer B;
	Pointer C;
	Pointer D;
};

#endif /* SQUARE_H_ */
