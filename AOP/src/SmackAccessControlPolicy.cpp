/*
 * SmackAccessControlPolicy.cpp
 *
 *  Created on: 2018-11-15
 *      Author: root
 */

#include "SmackAccessControlPolicy.h"

SmackAccessControlPolicy::SmackAccessControlPolicy(AccessControlPreProcess *ptr) : AccessControlPolicy(ptr)
{
	// TODO Auto-generated constructor stub

}
bool SmackAccessControlPolicy::ExecutePolicy()
{
	if (!AccessControlPolicy::ExecutePreProcess())
	{
		return false;
	}
	cout << "execute smack access control policy." << endl;
	return true;
}
SmackAccessControlPolicy::~SmackAccessControlPolicy()
{
	// TODO Auto-generated destructor stub
}
