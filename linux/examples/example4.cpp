#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int array[4][4] = {{1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}};
    for (int i = 0;i < 4;i++)
    {
        if ((1 == array[i][1] + array[i][3]) && 
            (1 == array[i][1] + array[i][2]) && 
            (1 == array[i][0] + array[i][1]))
        {
            cout << i << endl;
        }
    }
    
    return 0;
}
