/*
 * Leaf1.cpp
 *
 *  Created on: 2118-11-17
 *      Author: root
 */

#include "Leaf1.h"

Leaf1::Leaf1()
{
	// TODO Auto-generated constructor stub

}
void Leaf1::Operate()
{
	cout << "I am leaf1...!" << endl;
	Component::Operate();
}
void Leaf1::SetImplementation()
{
	ImplementationPtr = make_shared<Implementation1>();
}
Leaf1::~Leaf1()
{
	// TODO Auto-generated destructor stub
}
