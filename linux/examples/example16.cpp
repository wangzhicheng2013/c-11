#include <string.h>
#include <iostream>
using namespace std;
typedef struct Test
{
    int a;
    long b;
    char c[0];
}Test;
int main()
{
    cout << sizeof(Test) << endl;
    Test test;
    char str[] = "abc";
    cout << test.c << endl;

    return 0;
}
