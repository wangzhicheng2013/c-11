/*
 * RoleBasedAccessControlPolicy.h
 *
 *  Created on: 2018-11-15
 *      Author: root
 */

#ifndef ROLEBASEDACCESSCONTROLPOLICY_H_
#define ROLEBASEDACCESSCONTROLPOLICY_H_

#include "AccessControlPolicy.h"
class RoleBasedAccessControlPolicy: public AccessControlPolicy
{
public:
	RoleBasedAccessControlPolicy(AccessControlPreProcess *);
	virtual ~RoleBasedAccessControlPolicy();
public:
	virtual bool ExecutePolicy() override;
};

#endif /* ROLEBASEDACCESSCONTROLPOLICY_H_ */
