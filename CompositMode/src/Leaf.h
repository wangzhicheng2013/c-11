/*
 * Leaf.h
 *
 *  Created on: 2018-11-16
 *      Author: root
 */

#ifndef LEAF_H_
#define LEAF_H_

#include "Component.h"

class Leaf: public Component {
public:
	Leaf();
	virtual ~Leaf();
public:
	virtual void Operate() override;
};

#endif /* LEAF_H_ */
