/*
 * AccessControlPreProcess.h
 *
 *  Created on: 2018-11-14
 *      Author: root
 */

#ifndef ACCESSCONTROLPREPROCESS_H_
#define ACCESSCONTROLPREPROCESS_H_

#include "AccessControlPolicy.h"

class AccessControlPreProcess: public AccessControlPolicy
{
public:
	AccessControlPreProcess(AccessControlPolicy *);
	virtual ~AccessControlPreProcess();
public:
	virtual bool ExecutePolicy() override;
	virtual bool ExecutePreProcess() = 0;
private:
	AccessControlPolicy *pAccessControlPolicy;
};

#endif /* ACCESSCONTROLPREPROCESS_H_ */
