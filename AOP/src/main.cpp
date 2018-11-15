/*
 * main.cpp
 *
 *  Created on: 2018-11-15
 *      Author: root
 */
#include "RoleBasedAccessControlPolicy.h"
#include "SmackAccessControlPolicy.h"
#include "CheckDataValidity.h"
int main()
{
	CheckDataValidity checkDataValidity;
	RoleBasedAccessControlPolicy roleBasedAccessControlPolicy(&checkDataValidity);
	roleBasedAccessControlPolicy.ExecutePolicy();
	SmackAccessControlPolicy smackAccessControlPolicy(&checkDataValidity);
	smackAccessControlPolicy.ExecutePolicy();

	return 0;
}
