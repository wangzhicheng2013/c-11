/*
 * BaseAspect.h
 *
 *  Created on: 2018-11-14
 *      Author: root
 */

#ifndef BASEASPECT_H_
#define BASEASPECT_H_
#include <memory>
using namespace std;
template <typename WrappedType, typename DerivedAspect>
class BaseAspect
{
public:
	explicit BaseAspect(WrappedType *);
	virtual ~BaseAspect();
public:
	void Before(WrappedType *ptr)
	{
	}
	void After(WrappedType *ptr)
	{
	}
	shared_ptr<WrappedType> operator ->()
	{
		GetDerived()->Before(wrappedPtr);
	}
protected:
	DerivedAspect *GetDerived()
	{
		return reinterpret_cast<DerivedAspect *>(this);
	}
	class AfterWrapper
	{
	public:
		AfterWrapper(DerivedAspect *ptr) : pDerivedAspect(ptr)
		{
		}
		void operator ()(WrappedType *ptr)
		{
			pDerivedAspect->After(ptr);
		}
	public:
		DerivedAspect *pDerivedAspect;

	};
protected:
	WrappedType *wrappedPtr;
};
template <template<typename>class Aspect, typename WrappedType>
Aspect<WrappedType> MakeAspect(WrappedType *p)
{
	return Aspect<WrappedType>(p);
}
#endif /* BASEASPECT_H_ */
