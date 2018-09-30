/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-09-30
Description:square class
ChangeLog:
			1. create this file
**************************************************/

#include "Square.h"

Square::Square()
{
	// TODO Auto-generated constructor stub

}
/*
 * @purpose:get shape type
 * */
ShapeType Square::GetShapeType()
{
	if ((A.GetDistance(B) == B.GetDistance(C)) && (A.GetDistance(C) == B.GetDistance(D)))
	{
		return SQUARE;
	}
	return UNKNOWN;
}
Square::~Square()
{
	// TODO Auto-generated destructor stub
}
