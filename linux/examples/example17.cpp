//https://www.linuxidc.com/Linux/2019-01/156341.htm
#include <stdint.h>
#include <iostream>
#include <cmath>
using namespace std;
int x = 13;
int y = 13;
const int LOOP = 1000000;
int fun0()
{
    int last = 1;
    for (int i = 1;i <= y;i++)
    {
        last = last * x % 1000;
    }
    return last;
}
int fun1()
{
    uint64_t t = pow(x, y);
    return t % 1000;
}
int main()
{
    // 0.1453s
    /*for (int i = 0;i < LOOP;i++)
    {
        fun0();
    }*/
    // 0.191s
    for (int i = 0;i < LOOP;i++)
    {
        fun1();
    }
    
    return 0;
}
