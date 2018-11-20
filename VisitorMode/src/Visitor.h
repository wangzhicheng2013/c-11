/*
 * Visitor.h
 *
 *  Created on: 2018-11-20
 *      Author: root
 */

#ifndef VISITOR_H_
#define VISITOR_H_
template <typename T>
class Visitor {
public:
	Visitor()
	{
	}
	virtual ~Visitor()
	{
	}
public:
	virtual void Visit(T&) = 0;
};

#endif /* VISITOR_H_ */
