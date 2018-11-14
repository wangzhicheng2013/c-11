/*
 * BaseAspect.cpp
 *
 *  Created on: 2018-11-14
 *      Author: root
 */

#include "BaseAspect.h"
template <typename WrappedType, typename DerivedAspect>
BaseAspect<WrappedType, DerivedAspect>::BaseAspect(WrappedType *ptr) : wrappedPtr(ptr)
{
	// TODO Auto-generated constructor stub
}
template <typename WrappedType, typename DerivedAspect>
BaseAspect<WrappedType, DerivedAspect>::~BaseAspect()
{
	// TODO Auto-generated destructor stub
}
