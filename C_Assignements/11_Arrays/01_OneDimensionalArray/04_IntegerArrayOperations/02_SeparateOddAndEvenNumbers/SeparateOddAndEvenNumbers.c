#include <stdio.h>

#define NUM_ELEMENTS 10

int main(void)
{
    // variable declarations
    int iArray_vtg[NUM_ELEMENTS];
    int i_vtg, num_vtg, sum_vtg = 0;

    // code
    printf("\n\n");

    // *** ARRAY ELEMENTS INPUT ***
    printf("Enter integer elements for array: \n\n");
    for (i_vtg = 0; i_vtg < NUM_ELEMENTS; i_vtg++)
    {
        scanf("%d", &num_vtg);
        iArray_vtg[i_vtg] = num_vtg;
    }

    // *** SEPARATE OUT EVEN NUMBERS FROM ARRAY ELEMENTS ***
    printf("\n\n");
    printf("Even numbers among the array elements are: \n\n");
    for (i_vtg = 0; i_vtg < NUM_ELEMENTS; i_vtg++)
    {
        if ((iArray_vtg[i_vtg] % 2) == 0)
        {
            printf("%d\n", iArray_vtg[i_vtg]);
        }
    }

    // *** SEPARATING OUT ODD NUMBERS FROM ARRAY ELEMENTS ***
    printf("\n\n");
    printf("Odd numbers amongst the array elements are: \n\n");
    for (i_vtg = 0; i_vtg < NUM_ELEMENTS; i_vtg++)
    {
        if ((iArray_vtg[i_vtg] % 2) != 0)
        {
            printf("%d\n", iArray_vtg[i_vtg]);
        }
    }

    return (0);
}