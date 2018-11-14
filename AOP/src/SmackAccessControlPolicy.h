/*
 * SmackAccessControlPolicy.h
 *
 *  Created on: 2018-11-14
 *      Author: root
 */

#ifndef SMACKACCESSCONTROLPOLICY_H_
#define SMACKACCESSCONTROLPOLICY_H_

#include "AccessControlPolicy.h"

class SmackAccessControlPolicy: public AccessControlPolicy
{
public:
	SmackAccessControlPolicy();
	virtual ~SmackAccessControlPolicy();
public:
	virtual bool ExecutePolicy() override;
};

#endif /* SMACKACCESSCONTROLPOLICY_H_ */
