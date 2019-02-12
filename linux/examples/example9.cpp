#include <iostream>
#include <map>
#include <memory>
using namespace std;
map<int, shared_ptr<int> >mapper;
shared_ptr<int>ptr0;
shared_ptr<int>ptr1;
void fun1(shared_ptr<int>&ptr)
{
    mapper[10] = ptr;
}
void fun(int i)
{
    shared_ptr<int>ptr(new int(10));
//  fun1(ptr);
    if (0 == i)
    {
        ptr0 = ptr;
    }
    else
    {
        ptr1 = ptr;
    }
}
int main()
{
    for (int i = 0;i < 2;i++)
    {
        fun(i);
    }
    cout << (ptr0.get()) << endl;
    cout << (ptr1.get()) << endl;
    cout << *ptr0 << endl;
    cout << *ptr1 << endl;
//  cout << *(mapper[10]) << endl;

    return 0;
}
