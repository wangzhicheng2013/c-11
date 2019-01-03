#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;
using namespace chrono;
static const int LOOP = 10000;
bool CopyFile(const char *src_file_path, const char *dest_file_path)
{
    fstream src_file(src_file_path, ios::in | ios::binary);
    if(!src_file || !src_file.is_open())
    {
        cerr << src_file_path << " open failed...!" << endl;
        return false;
    }
    fstream dest_file(dest_file_path, ios::out | ios::binary);
    if(!dest_file || !dest_file.is_open())
    {
        cerr << dest_file_path << " open failed...!" << endl;
        src_file.close();
        return false;
    }
    dest_file << src_file.rdbuf();
    src_file.close();
    dest_file.close();
    return true;
}
int main()
{
    auto start = system_clock::now();
    for (int i = 0;i < LOOP;i++)
    {
        CopyFile("./example0.cpp", "./example1.cpp");
    }
    auto end = system_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "eclipse time = " << double(duration.count()) * microseconds::period::num / microseconds::period::den << "s" << endl;

    return 0;
}
