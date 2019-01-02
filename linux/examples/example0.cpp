#include <iostream>
#include <fstream>
using namespace std;
bool CopyFile()
int main()
{
    ifstream infile("./example0.cpp");
    cout << infile.rdbuf() << endl;
    infile.close();

    return 0;
}
