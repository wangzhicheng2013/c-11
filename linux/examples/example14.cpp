#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/file.h>
#include <string.h>
#include <iostream>
#include <thread>
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
int main()
{
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

    return 0;
}
