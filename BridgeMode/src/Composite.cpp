/*
 * Composite.cpp
 *
 *  Created on: 2018-11-17
 *      Author: root
 */

#include "Composite.h"

Composite::Composite()
{
	// TODO Auto-generated constructor stub

}
void Composite::Add(shared_ptr<Component>&&ptr)
{
	components.emplace_back(ptr);
}
void Composite::Operate()
{
	for (auto &it : components)
	{
		it->Operate();
	}
}
void Composite::SetImplementation()
{
	for (auto &it : components)
	{
		it->SetImplementation();
	}
}
Composite::~Composite()
{
	// TODO Auto-generated destructor stub
}
