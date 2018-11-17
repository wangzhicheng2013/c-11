/*
 * Implementation.h
 *
 *  Created on: 2018-11-17
 *      Author: root
 */

#ifndef IMPLEMENTATION_H_
#define IMPLEMENTATION_H_
class Implementation {
public:
	Implementation();
	virtual ~Implementation();
public:
	virtual void Operate() = 0;
};

#endif /* IMPLEMENTATION_H_ */
