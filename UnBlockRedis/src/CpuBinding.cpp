/*
 * CpuBinding.cpp
 *
 *  Created on: 2019-2-19
 *      Author: root
 */

#include "CpuBinding.h"
CpuBinding CpuBinding::cpuBinding;
CpuBinding::CpuBinding()
{
	cpu_num = thread::hardware_concurrency();
}
/*
 * @purpose:bind for process cpu start from 1
 * */
bool CpuBinding::BindForProcess(int cpu)
{
	if (cpu < 0)
	{
		return false;
	}
	cpu = cpu % cpu_num;
	if (0 == cpu)
	{
		cpu = 1;
	}
	cpu_set_t cpuSet = {0};
	//CPU_ZERO(&cpuSet);
	CPU_SET(cpu, &cpuSet);
	return sched_setaffinity(0, sizeof(cpuSet), &cpuSet) >= 0;
}
/*
 * @purpose:bind for thread cpu start from 1
 * */
bool CpuBinding::BindForThread(int cpu)
{
	if (cpu < 0)
	{
		return false;
	}
	cpu = cpu % cpu_num;
	if (0 == cpu)
	{
		cpu = 1;
	}
	cpu_set_t cpuSet = {0};
	//CPU_ZERO(&cpuSet);
	CPU_SET(cpu, &cpuSet);
	return pthread_setaffinity_np(pthread_self(), sizeof(cpuSet), &cpuSet) >= 0;
}
CpuBinding::~CpuBinding()
{
}
