/*
 * CheckDataValidity.h
 *
 *  Created on: 2018-11-14
 *      Author: root
 */

#ifndef CHECKDATAVALIDITY_H_
#define CHECKDATAVALIDITY_H_

#include "AccessControlPreProcess.h"

class CheckDataValidity: public AccessControlPreProcess
{
public:
	CheckDataValidity(AccessControlPolicy *);
	virtual ~CheckDataValidity();
public:
	virtual bool ExecutePreProcess() override;
};

#endif /* CHECKDATAVALIDITY_H_ */
