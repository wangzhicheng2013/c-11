/*
 * Implementation0.h
 *
 *  Created on: 2018-11-17
 *      Author: root
 */

#ifndef IMPLEMENTATION0_H_
#define IMPLEMENTATION0_H_
#include <iostream>
#include "Implementation.h"
using namespace std;

class Implementation0: public Implementation {
public:
	Implementation0();
	virtual ~Implementation0();
public:
	virtual void Operate() override;
};

#endif /* IMPLEMENTATION0_H_ */
