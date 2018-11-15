/*
 * AccessControlPreProcess.h
 *
 *  Created on: 2018-11-15
 *      Author: root
 */

#ifndef ACCESSCONTROLPREPROCESS_H_
#define ACCESSCONTROLPREPROCESS_H_
#include <iostream>
using namespace std;
class AccessControlPreProcess
{
public:
	AccessControlPreProcess();
	virtual ~AccessControlPreProcess();
public:
	virtual bool ExecutePreProcess() = 0;
};

#endif /* ACCESSCONTROLPREPROCESS_H_ */
