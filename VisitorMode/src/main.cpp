/*
 * main.cpp
 *
 *  Created on: 2018-11-20
 *      Author: root
 */
#include "PrintVisitor.h"
int main()
{
	PrintVisitor pv;
	A a;
	Base<A>*base = &a;
	base->Accept(pv);
	return 0;
}
