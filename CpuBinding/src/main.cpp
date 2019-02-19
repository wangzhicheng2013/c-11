/*
 * main.cpp
 *
 *  Created on: 2019-2-19
 *      Author: root
 */
#include "CpuBinding.h"
#include <iostream>
const long N = 100000000;
void fun(int cpu)
{
	if (false == CpuBinding::GetInstance().BindForThread(cpu))
	{
		cerr << "thread bind cpu = " << cpu << " failed...!" << endl;
		return;
	}
	for (int loop = 0;loop < 1000;loop++)
	{
		long sum = 0;
		long d = 0;
		for (long i = 0;i < N;i++)
		{
			sum += i;
			d = d + i;
		}
	}
}
int main()
{
	thread th0(fun, 1);
	thread th1(fun, 2);
	th0.join();
	th1.join();
	return 0;
}
