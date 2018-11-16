/*
 * Composite.h
 *
 *  Created on: 2018-11-16
 *      Author: root
 */

#ifndef COMPOSITE_H_
#define COMPOSITE_H_
#include <vector>
#include "Component.h"

class Composite: public Component {
public:
	Composite();
	virtual ~Composite();
public:
	virtual void Add(shared_ptr<Component>&&) override;
	virtual void Operate() override;
private:
	vector<shared_ptr<Component> >components;
};

#endif /* COMPOSITE_H_ */
