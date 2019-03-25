#include <stdio.h>
#include <fcntl.h>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
const char *filepath = "./example2.cpp";
const int LOOP = 100000;
const int SIZE = 1024;
void Read0()
{
    fstream fs(filepath);
    if (!fs)
    {
        cerr << "file open failed...!" << endl;
        return;
    }
//  string line;
    char buf[SIZE] = "";
    while (!fs.eof())
    {
//      fs >> line;
        fs.getline(buf, SIZE);
    }
    fs.close();
}
void Read1()
{
    char buf[SIZE] = "";
    FILE *fp = fopen(filepath, "r");
    if (NULL == fp)
    {
        cerr << "file open failed...!" << endl;
        return;
    }
    while (fgets(buf, SIZE, fp) != NULL)
    {
    }
    fclose(fp);
}
int main()
{
    for (int i = 0;i < LOOP;i++)
    {
        Read0();    // 9.50 => 2.250(remove cin >> line)
//      Read1();    // 2.734
    }
    
    return 0;
}
