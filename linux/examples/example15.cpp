#include <iostream>
using namespace std;
inline int add(int a, int b)
{
    return a + b;
}
int main()
{
    int t = 0;
    for (int i = 0;i < 1000000;i++)
    {
        t = add(i, i + 1);
    }

    return 0;
}
