/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-10-01
Description:square class
ChangeLog:
			1.create this file
			2.add ACCURACY_DEVIATION judgment
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
