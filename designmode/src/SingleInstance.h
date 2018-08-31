/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-08-23
Description:Single Instance design mode with C++11
ChangeLog:
			1. create this file
 **************************************************/
#ifndef SingleInstance_H_
#define SingleInstance_H_
#include <algorithm>
#include <exception>
using namespace std;
template <class T>
class SingleInstance
{
public:
	template <typename... Args>
	static T *Instance(Args&&... args)
	{
		if (nullptr == pInstance)
		{
			pInstance = new T(forward<Args>(args)...);
		}
		return pInstance;
	}
	static T *GetInstance()
	{
		if (nullptr == pInstance)
		{
			throw logic_error("the instance is not inited...");
		}
		return pInstance;
	}
	static void DestoryInstance()
	{
		if (pInstance != nullptr)
		{
			delete pInstance;
			pInstance = nullptr;
		}
	}
private:
	SingleInstance();
	virtual ~SingleInstance()
	{
		DestoryInstance();
	}
	SingleInstance(const SingleInstance &) = delete;
	SingleInstance & operator = (const SingleInstance &) = delete;
private:
	static T *pInstance;
};
template <class T>
T *SingleInstance<T>::pInstance = nullptr;


#endif /* SingleInstance_H_ */
