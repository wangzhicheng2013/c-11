#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Test
{
public:
    Test(int i = 0, int j = 0) : a(i), b(j)
    {
    }
public:
    int a;
    int b;
};
auto get_URBG()
{
    random_device rd;
    mt19937 g(rd());
    return g;
}
int main()
{
    vector<int>v;
    vector<Test>v1;
    int N = 100;
    for (int i = 0;i < N;i++)
    {
        v.emplace_back(i);
        v1.emplace_back(Test(i, i + 1));
    }
    shuffle(begin(v), end(v), get_URBG());
    Test t1, t2(1, 1);
    swap(t1, t2);
    for (auto &it : v)
    {
        cout << it << endl;
    }
    cout << t1.a << " " << t1.b << endl;

    return 0;
}
