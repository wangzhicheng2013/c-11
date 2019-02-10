#include <stdlib.h>
#include <iostream>
using namespace std;
void fun()
{
    cout << "exit...!" << endl;
}
int main()
{
    atexit(fun);
    cout << "main exit...!" << endl;

    return 0;
}
