/*
 * AccessControlPolicy.h
 *
 *  Created on: 2018-11-15
 *      Author: root
 */

#ifndef ACCESSCONTROLPOLICY_H_
#define ACCESSCONTROLPOLICY_H_
#include "AccessControlPreProcess.h"

class AccessControlPolicy
{
public:
	AccessControlPolicy(AccessControlPreProcess *);
	virtual ~AccessControlPolicy();
public:
	virtual bool ExecutePolicy() = 0;
	bool ExecutePreProcess()
	{
		return pAccessControlPreProcess->ExecutePreProcess();
	}
private:
	AccessControlPreProcess *pAccessControlPreProcess;
};

#endif /* ACCESSCONTROLPOLICY_H_ */
