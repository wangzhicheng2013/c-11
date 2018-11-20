/*
 * Base.h
 *
 *  Created on: 2018-11-20
 *      Author: root
 */

#ifndef BASE_H_
#define BASE_H_
#include "Visitor.h"
template<typename T>
class Base
{
public:
	Base()
	{
	}
	virtual ~Base()
	{
	}
public:
	virtual void Accept(Visitor<T>&) = 0;

};
class A : public Base<A>
{
public:
	void Accept(Visitor<A>&v)
	{
		v.Visit(*this);
	}
public:
	int val;
};
class B : public Base<B>
{
public:
	void Accept(Visitor<B>&v)
	{
		v.Visit(*this);
	}
public:
	int val;
};
#endif /* BASE_H_ */
