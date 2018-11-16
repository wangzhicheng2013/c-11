/*
 * main.cpp
 *
 *  Created on: 2018-11-16
 *      Author: root
 */
#include "Leaf.h"
#include "Composite.h"
int main()
{
	shared_ptr<Leaf>pComponent(new Leaf);
	Composite composite;
	composite.Add(move(pComponent));
	composite.Operate();
	return 0;
}
