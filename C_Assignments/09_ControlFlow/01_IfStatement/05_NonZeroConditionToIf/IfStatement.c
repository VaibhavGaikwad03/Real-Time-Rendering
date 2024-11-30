#include <stdio.h>

int main(void)
{
    // variable declarations
    int a;

    // code
    printf("\n\n");

    a = 5;
    if (a) // Non-zero positive value
    {
        printf("if-block 1: 'A' exists and has value = %d!!!\n\n", a);
    }

    a = -5;
    if (a) // Non-zero negative value
    {
        printf("if-block 2: 'A' exists and value = %d!!!\n\n", a);
    }

    a = 0;
    if (a) // Zero value
    {
        printf("if-block 3: 'A' exists and has value = %d!!!\n\n", a);
    }

    printf("All three if-statements are done!!!\n\n");

    return (0);
}