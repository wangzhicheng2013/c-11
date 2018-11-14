/*
 * CheckDataValidity.cpp
 *
 *  Created on: 2018-11-14
 *      Author: root
 */

#include "CheckDataValidity.h"

CheckDataValidity::CheckDataValidity(AccessControlPolicy *ptr) : AccessControlPreProcess(ptr)
{
	// TODO Auto-generated constructor stub

}
bool CheckDataValidity::ExecutePreProcess()
{
	cout << "execute pre process for access control policy." << endl;
	return true;
}
CheckDataValidity::~CheckDataValidity()
{
	// TODO Auto-generated destructor stub
}
