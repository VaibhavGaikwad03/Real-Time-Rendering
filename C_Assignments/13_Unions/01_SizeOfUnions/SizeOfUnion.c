#include <stdio.h>

struct MyStruct
{
    int i;
    float f;
    double d;
    char c;
};

union MyUnion
{
    int i;
    float f;
    double d;
    char c;
};

int main(void)
{
    // variable declarations
    struct MyStruct s;
    union MyUnion u;

    // code
    printf("\n\n");
    printf("Size of MyStruct = %lu\n", sizeof(s));
    printf("\n\n");
    printf("Size of MyUnion = %lu\n", sizeof(u));

    return (0);
}