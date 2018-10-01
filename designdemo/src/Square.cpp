/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-10-01
Description:square class
ChangeLog:
			1.create this file
			2.add ACCURACY_DEVIATION judgment
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
	double diff0 = fabs(A.GetDistance(B) - B.GetDistance(C));
	double diff1 = fabs(A.GetDistance(C) - B.GetDistance(D));
	if (diff0 <= ACCURACY_DEVIATION && diff1 <= ACCURACY_DEVIATION)
	{
		return SQUARE;
	}
	return UNKNOWN;
}
Square::~Square()
{
	// TODO Auto-generated destructor stub
}
