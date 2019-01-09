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
        vec_new.resize(THREE);
        sorted = false;
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
        copy(begin(vec), end(vec), begin(vec_new));
        return true;
    }
    void SortVecNew()
    {
        if (false == sorted)
        {
            sort(begin(vec_new), end(vec_new));
            sorted = true;
        }
    }
    void GetMaxNumber(int &max_number)
    {
        SortVecNew();
        max_number = 0;
        for (int i = THREE - 1;i >= 0;i--)
        {
            max_number = ((max_number << 3) + (max_number << 1));
            max_number += vec_new[i];
        }
    }
    void GetMinNumber(int &min_number)
    {
        SortVecNew();
        min_number = 0;
        for (int i = 0;i < THREE;i++)
        {
            min_number = ((min_number << 3) + (min_number << 1));
            min_number += vec_new[i];
        }
    }
public:
    int number;
    vector<int>vec;
    vector<int>vec_new;
    const int THREE = 3;
    bool sorted;
};
bool IsBlackHoleNumber(int number, int &black)
{
    int min_number = 0;
    int max_number = 0;
    int diff = 0;
    while (true)
    {
        ThreeNumber three(number);
        if (false == three.GetThree())
        {
            return false;
        }
        three.GetMinNumber(min_number);
        three.GetMaxNumber(max_number);
        diff = max_number - min_number;
        cout << "Max = " << max_number << endl;
        cout << "Min = " << min_number << endl;
        cout << "diff = " << diff << endl;
        cout << "number = " << number << endl;
        if (diff == number)
        {
            black = number;
            return true;
        }
        if (diff <= 0)
        {
            return false;
        }
        number = diff;
    }
}
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
void TestGetMinNumber()
{
    ThreeNumber three(207);
    if (three.GetThree())
    {
        cout << three.vec[0] << endl;
        cout << three.vec[1] << endl;
        cout << three.vec[2] << endl;
        cout << "Test GetThree Pass." << endl;
        int min_number;
        three.GetMinNumber(min_number);
        if (27 == min_number)
        {
            cout << "Test GetMinNumber Pass." << endl;
        }
        else
        {
            cout << min_number << " Test GetMinNumber failed...!" << endl;
        }
    }
    else
    {
        cerr << "Test GetThree failed...!" << endl;
    }
}
void TestIsBlackHoleNumber()
{
    int number = 207;
    int black = 0;
    if (true == IsBlackHoleNumber(number, black))
    {
        cout << black << " is black hole number." << endl;
        cout << "Test IsBlackHoleNumber success." << endl;
    }
    number = 555;
    if (false == IsBlackHoleNumber(number, black))
    {
        cout << number << " is not black hole number." << endl;
        cout << "Test IsBlackHoleNumber success." << endl;
    }
    number = 123;
    if (false == IsBlackHoleNumber(number, black))
    {
        cout << number << " is not black hole number." << endl;
        cout << "Test IsBlackHoleNumber success." << endl;
    }
    else
    {
        cout << black << endl;
    }


}
int main()
{
    TestGetMaxNumber();
    TestGetMinNumber();
    TestIsBlackHoleNumber();

    return 0;
}
