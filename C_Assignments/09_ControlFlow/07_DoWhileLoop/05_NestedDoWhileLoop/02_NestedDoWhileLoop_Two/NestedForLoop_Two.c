#include <stdio.h>

int main(void)
{
    // variable declarations
    int i, j, k;

    // code
    printf("\n\n");

    i = 1;
    do
    {
        printf("i = %d\n", i);
        printf("-----------\n\n");

        j = 1;
        do
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
        } while (j <= 5);
        i++;
        printf("\n\n");
    } while (i <= 10);

    return (0);
}