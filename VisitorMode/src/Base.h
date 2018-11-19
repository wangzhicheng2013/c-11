/*
 * Base.h
 *
 *  Created on: 2018-11-19
 *      Author: root
 */

#ifndef BASE_H_
#define BASE_H_
#include "Visitor.h"
class A;
class B;
class Base
{
public:
	using MyVisitor = Visitor<A, B>;
	Base();
	virtual ~Base();
};
class A : public Base
{

};
class B : public Base
{

};
#endif /* BASE_H_ */
