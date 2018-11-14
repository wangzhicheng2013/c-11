/*
 * TimeElapsedAspect.h
 *
 *  Created on: 2018-11-14
 *      Author: root
 */

#ifndef TIMEELAPSEDASPECT_H_
#define TIMEELAPSEDASPECT_H_
#include "BaseAspect.h"
#include <iostream>
#include <chrono>
using time_point = chrono::time_point<chrono::system_clock, chrono::duration<double> >;
template <typename WrappedType>
class TimeElapsedAspect : public BaseAspect<WrappedType, TimeElapsedAspect<WrappedType> >
{
public:
	TimeElapsedAspect(WrappedType *);
	//virtual ~TimeElapsedAspect();
public:
	void Before(WrappedType *);
	void After(WrappedType *);
private:
	time_point start_time;
	time_point end_time;
};

#endif /* TIMEELAPSEDASPECT_H_ */
