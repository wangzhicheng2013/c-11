/*
 * AccessControlPreProcess.cpp
 *
 *  Created on: 2018-11-14
 *      Author: root
 */

#include "AccessControlPreProcess.h"

AccessControlPreProcess::AccessControlPreProcess(AccessControlPolicy *ptr)
{
	// TODO Auto-generated constructor stub
	pAccessControlPolicy = ptr;
}
bool AccessControlPreProcess::ExecutePolicy()
{
	return pAccessControlPolicy->ExecutePolicy();
}
AccessControlPreProcess::~AccessControlPreProcess() {
	// TODO Auto-generated destructor stub
}
