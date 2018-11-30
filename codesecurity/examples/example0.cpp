#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
void fun(char *&p)
{
    p = (char *)malloc(128);
    cout << "p = " << p << endl;
}
int main()
{
    cout << "hello code security...!" << endl;
    char *p = NULL;
    fun(p);
    cout << p << endl;
    if (p)
    {
        free(p);
        p = NULL;
    }
}
