#include <stdio.h>
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
int main()
{
    printf("%zu\n", sizeof(struct Name));
    printf("%zu\n", sizeof(struct People));

    return 0;
}
