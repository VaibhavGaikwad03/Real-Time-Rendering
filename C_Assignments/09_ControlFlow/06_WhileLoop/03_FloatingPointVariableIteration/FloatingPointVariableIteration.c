#include <stdio.h>

int main(void)
{
    // variable declarations
    float f;
    float f_num = 1.7f; // simply change this value ONLY to get difference outputs...

    // code
    printf("\n\n");

    printf("Printing numbers %f to %f: \n\n", f_num, (f_num * 10.0f));
    f = f_num;
    while (f <= (f_num * 10.0f))
    {
        printf("\t%f\n", f);
        f = f + f_num;
    }

    printf("\n\n");

    return (0);
}