#include <stdlib.h>
#include <unistd.h>
int main()
{
    char *p = (char *)malloc(1024 * 1024 * 1024);
    if (p)
    {
        free(p);
        p = NULL;
    }
    while (true)
    {
        sleep(10);
    }
    return 0;
}
