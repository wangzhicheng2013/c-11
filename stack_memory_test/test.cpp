#include <string.h>
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
using namespace std;
static const int BUFFER_SIZE = 2048;
static const int THREAD_NUM = 8;
char TMP[BUFFER_SIZE] = "";
void fun()
{
    while (true)
    {
        for (int i = 0;i < 5000;i++)
        {
            char buf[BUFFER_SIZE] = "";
            memcpy(buf, TMP, BUFFER_SIZE);
        }
        this_thread::sleep_for(chrono::seconds(1));
    }
}
int main()
{
    for (int i = 0;i < BUFFER_SIZE - 1;i++)
    {
        TMP[i] = 'A';
    }
    vector<thread>vec;
    for (int i = 0;i < THREAD_NUM;i++)
    {
        vec.emplace_back(thread(fun));
    }
    for (auto &it : vec)
    {
        it.join();
    }
    return 0;
}
