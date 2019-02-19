#include <sched.h>
#include <pthread.h>
#include <iostream>
#include <thread>
using namespace std;
const long N = 100000000;
void fun(int cpu)
{
    cpu_set_t cpuSet;
    CPU_ZERO(&cpuSet);
    CPU_SET(cpu, &cpuSet);
    if (pthread_setaffinity_np(pthread_self(), sizeof(cpuSet), &cpuSet) < 0)
    {
        cerr << "cpu " << cpu << " thread bind failed...!" << endl;
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
