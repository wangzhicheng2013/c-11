/*
 * Implementation1.h
 *
 *  Created on: 2118-11-17
 *      Author: root
 */

#ifndef IMPLEMENTATION1_H_
#define IMPLEMENTATION1_H_
#include <iostream>
#include "Implementation.h"
using namespace std;

class Implementation1: public Implementation {
public:
	Implementation1();
	virtual ~Implementation1();
public:
	virtual void Operate() override;
};

#endif /* IMPLEMENTATION1_H_ */
