/*
 * Leaf1.h
 *
 *  Created on: 2118-11-17
 *      Author: root
 */

#ifndef LEAF1_H_
#define LEAF1_H_

#include "Component.h"
#include "Implementation1.h"

class Leaf1: public Component {
public:
	Leaf1();
	virtual ~Leaf1();
public:
	virtual void Operate() override;
	virtual void SetImplementation() override;
};

#endif /* LEAF_H_ */
