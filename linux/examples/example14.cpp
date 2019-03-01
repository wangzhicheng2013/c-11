#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/file.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <thread>
#include <mutex>
using namespace std;
bool FileLock(int fd, unsigned char lock_type)
{
    struct flock lock = {0};
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_type = lock_type;
    lock.l_pid = -1;
    cout << "LLLL" << endl;
    if (fcntl(fd, F_SETLKW, &lock) < 0)
    {
        cerr << "set lock failed...!" << endl;
        return false;
    }
    switch(lock.l_type)
    {
    case F_RDLCK:
        printf("Read lock set by %d \n", getpid());
        break;
    case F_WRLCK:
        printf("write lock set by %d \n", getpid());
        break;
    case F_UNLCK:
        printf("Release lock by %d \n", getpid());
        break;
    default:
        break;
    }
    return true;
}
mutex global_lock;
void WriteFileThread()
{
    fstream os("./11.txt");
    if (!os || !os.is_open())
    {
        cerr << "file open failed...!" << endl;
        return;
    }
    string str(1024, 'A');
    for (int j = 0;j < 4;j++)
    {
    string tmp;
    for (int i = 0;i < 100000;i++)
    {
        if (i % 2)
        {
            str[2] = 'B';
        }
        tmp += str;
        tmp += "\n";
        if (0 != i && (0 == i % 100))
        {
            os << tmp;
            tmp.clear();
        }
    }
    if (!tmp.empty())
    {
        os << tmp;
    }
    }
    os.close();
}
int main()
{
    /*
    int fd = open("./11.txt", O_RDWR);
    if (fd < 0)
    {
        return -1;
    }
    FileLock(fd, F_WRLCK);
    getchar();
    FileLock(fd, F_UNLCK);
    getchar();
    close(fd);
*/
    WriteFileThread();
    return 0;
    const int N = 4;
    vector<thread>vec;
    vec.resize(N);
    for (int i = 0;i < N;i++)
    {
        vec[i] = thread(WriteFileThread);
    }
    for (auto &it : vec)
    {
        it.join();
    }
    
    return 0;
}
