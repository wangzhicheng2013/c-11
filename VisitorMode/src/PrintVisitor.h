/*
 * PrintVisitor.h
 *
 *  Created on: 2018-11-20
 *      Author: root
 */

#ifndef PRINTVISITOR_H_
#define PRINTVISITOR_H_
#include "Base.h"
#include <iostream>
using namespace std;
class PrintVisitor : public Visitor<A>
{
public:
	PrintVisitor();
	virtual ~PrintVisitor();
public:
	void Visit(A &a)
	{
		cout << "I am A." << endl;
		a.val = 10;
		cout << a.val << endl;
	}
};

#endif /* PRINTVISITOR_H_ */
