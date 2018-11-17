/*
 * Component.h
 *
 *  Created on: 2018-11-17
 *      Author: root
 */

#ifndef COMPONENT_H_
#define COMPONENT_H_
#include <memory>
#include "Implementation.h"
using namespace std;
class Component {
public:
	Component();
	virtual ~Component();
public:
	virtual void Add(shared_ptr<Component>&&ptr)
	{
	}
	virtual void Operate()
	{
		if (ImplementationPtr)
		{
			ImplementationPtr->Operate();
		}
	}
	virtual void SetImplementation()
	{
	}
protected:
	shared_ptr<Implementation>ImplementationPtr;
};

#endif /* COMPONENT_H_ */
