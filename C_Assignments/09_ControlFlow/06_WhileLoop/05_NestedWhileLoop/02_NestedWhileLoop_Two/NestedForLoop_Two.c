#include <stdio.h>

int main(void)
{
    // variable declarations
    int i, j, k;

    // code
    printf("\n\n");

    i = 1;
    while (i <= 10)
    {
        printf("i = %d\n", i);
        printf("-----------\n\n");

        j = 1;
        while (j <= 5)
        {
            printf("\tj = %d\n", j);
            printf("------------\n\n");

            k = 1;
            while (k <= 3)
            {
                printf("\t\tk = %d\n", k);
                k++;
            }
            j++;
            printf("\n\n");
        }
        i++;
        printf("\n\n");
    }

    return (0);
}