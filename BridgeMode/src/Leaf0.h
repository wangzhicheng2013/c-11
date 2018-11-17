/*
 * Leaf0.h
 *
 *  Created on: 2018-11-17
 *      Author: root
 */

#ifndef LEAF0_H_
#define LEAF0_H_

#include "Component.h"
#include "Implementation0.h"

class Leaf0: public Component {
public:
	Leaf0();
	virtual ~Leaf0();
public:
	virtual void Operate() override;
	virtual void SetImplementation() override;
};

#endif /* LEAF_H_ */
