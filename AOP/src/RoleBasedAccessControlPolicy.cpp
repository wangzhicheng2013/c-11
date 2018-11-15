/*
 * RoleBasedAccessControlPolicy.cpp
 *
 *  Created on: 2018-11-15
 *      Author: root
 */

#include "RoleBasedAccessControlPolicy.h"

RoleBasedAccessControlPolicy::RoleBasedAccessControlPolicy(AccessControlPreProcess *ptr) : AccessControlPolicy(ptr)
{
	// TODO Auto-generated constructor stub

}
bool RoleBasedAccessControlPolicy::ExecutePolicy()
{
	if (!AccessControlPolicy::ExecutePreProcess())
	{
		return false;
	}
	cout << "execute role based access control policy." << endl;
	return true;
}
RoleBasedAccessControlPolicy::~RoleBasedAccessControlPolicy()
{
	// TODO Auto-generated destructor stub
}
