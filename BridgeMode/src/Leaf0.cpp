/*
 * Leaf0.cpp
 *
 *  Created on: 2018-11-17
 *      Author: root
 */

#include "Leaf0.h"

Leaf0::Leaf0()
{
	// TODO Auto-generated constructor stub

}
void Leaf0::Operate()
{
	cout << "I am leaf0...!" << endl;
	Component::Operate();
}
void Leaf0::SetImplementation()
{
	ImplementationPtr = make_shared<Implementation0>();
}
Leaf0::~Leaf0()
{
	// TODO Auto-generated destructor stub
}
