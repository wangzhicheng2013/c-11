#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdalign.h>
struct Name
{
    int len;
    char names[];
};
struct People
{
    int id;
    alignas(struct Name) char names[sizeof(struct Name) + 128];
};
void fun0(int n)
{
    printf("fun0\n");
}
void fun1(double n)
{
    printf("fun1\n");
}
#define FUN(n) \
    _Generic(n, \
                int      : fun0,\
                double   : fun1)(n)
int main()
{
    printf("%zu\n", sizeof(struct Name));
    printf("%zu\n", sizeof(struct People));
    struct People pe = {1};
    struct Name *name =(struct Name *)pe.names;
    strcpy(name->names, "hello world");
    printf("%zu\n", sizeof(struct Name));
    puts(name->names);
    printf("align = %zu\n", alignof(struct People));
    int n = 10;
    FUN(n);
    double n1 = 10;
    FUN(n1);
    printf("C version = %ld\n", __STDC_VERSION__);
    _Static_assert(__STDC_VERSION__ == 201112L, "it is c11 versin");
    char buf[1024] = "";

    return 0;
}
