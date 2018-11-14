/*
 * AccessControlPolicy.h
 *
 *  Created on: 2018-11-14
 *      Author: root
 */

#ifndef ACCESSCONTROLPOLICY_H_
#define ACCESSCONTROLPOLICY_H_
#include <iostream>
using namespace std;
class AccessControlPolicy {
public:
	AccessControlPolicy();
	virtual ~AccessControlPolicy();
public:
	virtual bool ExecutePolicy() = 0;
};

#endif /* ACCESSCONTROLPOLICY_H_ */
