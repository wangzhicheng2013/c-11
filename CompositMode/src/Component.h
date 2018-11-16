/*
 * Component.h
 *
 *  Created on: 2018-11-16
 *      Author: root
 */

#ifndef COMPONENT_H_
#define COMPONENT_H_
#include <iostream>
#include <memory>
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
	}
};

#endif /* COMPONENT_H_ */
