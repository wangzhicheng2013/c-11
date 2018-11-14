/*
 * TimeElapsedAspect.cpp
 *
 *  Created on: 2018-11-14
 *      Author: root
 */

#include "TimeElapsedAspect.h"
template <typename WrappedType>
TimeElapsedAspect<WrappedType>::TimeElapsedAspect(WrappedType *ptr) : BaseAspect<WrappedType, TimeElapsedAspect<WrappedType> >(ptr)
{
	// TODO Auto-generated constructor stub
}
template <typename WrappedType>
void TimeElapsedAspect<WrappedType>::Before(WrappedType *ptr)
{
	start_time = chrono::system_clock::now();
}
template <typename WrappedType>
void TimeElapsedAspect<WrappedType>::After(WrappedType *ptr)
{
	end_time = chrono::system_clock::now();
	start_time = chrono::system_clock::now();
	cout << "Elapse Time = " << (end_time - start_time).count() << endl;
}
/*template <typename WrappedType>
TimeElapsedAspect<WrappedType>::~TimeElapsedAspect()
{
	// TODO Auto-generated destructor stub
}*/
