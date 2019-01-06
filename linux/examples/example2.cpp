#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class ThreeNumber
{
public:
    ThreeNumber(int n) : number(n)
    {
        vec.resize(THREE);
    }
    bool GetThree()
    {
        if (number <= 0)
        {
            cerr << number << " is invalid...!" << endl;
            return false;
        }
        int trycnt = 0;
        int tmp = number;
        while (tmp)
        {
            vec[trycnt] = tmp % 10;
            tmp /= 10;
            if (++trycnt >= THREE)
            {
                break;
            }
        }
        if (0 != tmp)
        {
            return false;
        }
        return true;
    }
    void GetMaxNumber(int &max_number)
    {
        sort(begin(vec), end(vec));
        max_number = 0;
        for (int i = THREE - 1;i >= 0;i--)
        {
            max_number = ((max_number << 3) + (max_number << 1));
            max_number += vec[i];
        }
    }
public:
    int number;
    vector<int>vec;
    const int THREE = 3;
};
void TestGetThree()
{
    ThreeNumber three(128);
    if (three.GetThree())
    {
        cout << three.vec[0] << endl;
        cout << three.vec[1] << endl;
        cout << three.vec[2] << endl;
        cout << "Test GetThree Pass." << endl;
    }
    else
    {
        cerr << "Test GetThree failed...!" << endl;
    }
}
void TestGetMaxNumber()
{
    ThreeNumber three(128);
    if (three.GetThree())
    {
        cout << three.vec[0] << endl;
        cout << three.vec[1] << endl;
        cout << three.vec[2] << endl;
        cout << "Test GetThree Pass." << endl;
        int max_number;
        three.GetMaxNumber(max_number);
        if (821 == max_number)
        {
            cout << "Test GetMaxNumber Pass." << endl;
        }
        else
        {
            cout << max_number << " Test GetMaxNumber failed...!" << endl;
        }
    }
    else
    {
        cerr << "Test GetThree failed...!" << endl;
    }
}
int main()
{
    TestGetMaxNumber();

    return 0;
}
