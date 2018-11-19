/*
 * Visitor.h
 *
 *  Created on: 2018-11-19
 *      Author: root
 */

#ifndef VISITOR_H_
#define VISITOR_H_
template <typename T, typename... OtherT>
class Visitor {
public:
	Visitor()
	{
	}
	virtual ~Visitor()
	{
	}
public:
	using Visitor<OtherT...>::Visit;
	virtual void Visit(const T&) = 0;
};

#endif /* VISITOR_H_ */
