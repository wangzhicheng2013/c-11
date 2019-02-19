/*
 * CpuBinding.h
 *
 *  Created on: 2019-2-19
 *      Author: root
 */

#ifndef CPUBINDING_H_
#define CPUBINDING_H_
#include <sched.h>
#include <pthread.h>
#include <thread>
using namespace std;
class CpuBinding {
public:
	static CpuBinding &GetInstance()
	{
		return cpuBinding;
	}
	/*
	 * @purpose:get cpu number
	 * */
	inline int GetCpuNum() const
	{
		return cpu_num;
	}
	/*
	 * @purpose:bind for process cpu start from 1
	 * */
	bool BindForProcess(int cpu);
	/*
	 * @purpose:bind for thread cpu start from 1
	 * */
	bool BindForThread(int cpu);
private:
	CpuBinding();
	~CpuBinding();
private:
	static CpuBinding cpuBinding;
private:
	int cpu_num;
};

#endif /* CPUBINDING_H_ */
