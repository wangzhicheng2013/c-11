/*
 * main.cpp
 *
 *  Created on: 2018-11-17
 *      Author: root
 */
#include "Leaf0.h"
#include "Leaf1.h"
#include "Composite.h"
int main()
{
	shared_ptr<Component>root = make_shared<Composite>();
	shared_ptr<Component>leaf0 = make_shared<Leaf0>();
	shared_ptr<Component>leaf1 = make_shared<Leaf1>();
	root->Add(move(leaf0));
	root->Add(move(leaf1));
	root->SetImplementation();
	root->Operate();
	return 0;
}
