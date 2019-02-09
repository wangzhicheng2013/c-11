#include <iostream>
#include <string>
using namespace std;
void fun(const string &str)
{
    cout << str << endl;
}
int main()
{
    fun("hello world...!");

    return 0;
}
