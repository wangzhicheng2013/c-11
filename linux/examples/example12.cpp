#include <sched.h>
#include <iostream>
using namespace std;
const long N = 100000000;
void fun()
{
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
    unsigned long mask = 2;
    cpu_set_t cpuSet;
    CPU_ZERO(&cpuSet);
    CPU_SET(1, &cpuSet);
    if (sched_setaffinity(0, sizeof(cpuSet), &cpuSet) < 0)
    {
        cerr << "cpu 1 bind failed...!" << endl;
        return -1;
    }
    fun();

    return 0;
}
