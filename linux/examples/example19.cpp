#include <stdio.h>
#include <iostream>
using namespace std;
const int LOOP = 30000000;
const int SIZE = 1024;
int array[SIZE];
bool fun0(int start, int end, int x)
{
    if (start > end)
    {
        return false;
    }
    int mid = (start + end) >> 1;
    if (x == array[mid])
    {
        return true;
    }
    if (x > array[mid])
    {
        return fun0(mid + 1, end, x);
    }
    return fun0(start, mid - 1, x);
}
bool fun1(int start, int end, int x)
{
    int mid = 0;
    while (start <= end)
    {
        mid = (start + end) >> 1;
        if (x == array[mid])
        {
            return true;
        }
        if (x > array[mid])
        {
            start = mid + 1;
            continue;
        }
        end = mid - 1;
    }
    return false;
}
int main()
{
    for (int i = 0;i < SIZE;i++)
    {
        array[i] = 2 * i - 1;
    }
    for (int i = 0;i < LOOP;i++)
    {
        int x = 2 * i - 1;
        //fun0(0, SIZE - 1, x);   // 2.979s
        fun1(0, SIZE - 1, x);   // 1.997s
    }
    
    return 0;
}
