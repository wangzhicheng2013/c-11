#include <stdlib.h>
#include <iostream>
#include <vector>
#include <thread>
using namespace std;
const int N = 100;
void fun()
{
    
    char *p[N] = {0};
    for (int loop = 0;loop < N * N * N;loop++)
    {
    for (int i = 0;i < N;i++)
    {
        p[i] = new char[1024];
        if (nullptr == p[i])
        {
            cerr << "memory lack...!" << endl;
            exit(EXIT_FAILURE);
        }
        delete []p[i];
    }
    }
}
void fun1()
{
    
    char *p[N] = {0};
    for (int loop = 0;loop < 1000000 / 2;loop++)
    {
    for (int i = 0;i < N;i++)
    {
        p[i] = new char[1024];
        if (nullptr == p[i])
        {
            cerr << "memory lack...!" << endl;
            exit(EXIT_FAILURE);
        }
        delete []p[i];
    }
    }
}
int main()
{
//  fun(); 8s
    // 4s
    thread th0(fun1); 
    thread th1(fun1); 
    th0.join();
    th1.join();
    return 0;
}
