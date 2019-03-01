/*
 * main.cpp
 *
 *  Created on: 2019-2-19
 *      Author: root
 */
#include "CpuBinding.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
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
fstream os("./11.txt");
void WriteFileThread(int cpu)
{
	/*if (!CpuBinding::GetInstance().BindForThread(cpu))
	{
		return;
	}*/
    if (!os || !os.is_open())
    {
        cerr << "file open failed...!" << endl;
        return;
    }
    string str(1024, 'A');
    for (int j = 0;j < 3;j++)
    {
    for (int i = 0;i < 10000	00;i++)
    {
        if (i % 2)
        {
            str[2] = 'B';
        }
        os << str << endl;
    }
    }
    cout << "LLL" << endl;
}

int main()
{
	/*thread th0(fun, 1);
	thread th1(fun, 2);
	th0.join();
	th1.join();*/
    const int N = 3;
    /*vector<thread>vec;
    vec.resize(N);
    for (int i = 0;i < N;i++)
    {
        vec[i] = thread(WriteFileThread, i + 1);
    }
    for (auto &it : vec)
    {
        it.join();
    }*/

    for (int i = 0;i < 1;i++)
	{
		WriteFileThread(i);
	}
    os.flush();
     os.close();
	return 0;
}
