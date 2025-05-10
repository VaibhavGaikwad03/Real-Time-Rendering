#include <stdio.h>

#define NUM_ELEMENTS 10

int main(void)
{
    // variable declarations
    int iArray_vtg[NUM_ELEMENTS];
    int i_vtg, num_vtg, j_vtg, count_vtg = 0;

    // code
    printf("\n\n");

    // *** ARRAY ELEMENTS INPUT ***
    printf("Enter integer elements for array: \n\n");
    for (i_vtg = 0; i_vtg < NUM_ELEMENTS; i_vtg++)
    {
        scanf("%d", &num_vtg);

        // if 'num' is negative ( < 0 ), then convert it to positive (multiply by - 1 )

        if (num_vtg < 0)
        {
            num_vtg = -1 * num_vtg;
        }

        iArray_vtg[i_vtg] = num_vtg;
    }

    // *** PRINTING ENTIRE ARRAY ***
    printf("\n\n");
    printf("Array elements are: \n\n");
    for (i_vtg = 0; i_vtg < NUM_ELEMENTS; i_vtg++)
    {
        printf("%d\n", iArray_vtg[i_vtg]);
    }

    // *** SEPARATING OUT EVEN NUMBERS FROM ARRAY ELEMENTS ***
    printf("\n\n");
    printf("Prime numbers amongts the array elements are: \n\n");
    for (i_vtg = 0; i_vtg < NUM_ELEMENTS; i_vtg++)
    {
        for (j_vtg = 1; j_vtg <= iArray_vtg[i_vtg]; j_vtg++)
        {
            if ((iArray_vtg[i_vtg] % j_vtg) == 0)
                count_vtg++;
        }

        // NUMBER 1 IS NEITHER A PRIME NUMBER NOR A CONSONANT
        // IF A NUMBER IS PRIME, IT IS ONLY DIVISIBLE BY 1 AND ITSELF
        // HENCE, IF A NUMBER IS PRIME, THE VALUE OF 'count' WILL BE EXACTLY 2
        // IF THE VALUE OF 'count' IS GREATER THAN 2, THE NUMBER IS DIVISIBLE BY NUMBERS OTHER THAN 1 AND HENCE, IT IS NOT PRIME
        // THE VALUE OF 'count' WILL BE 1 ONLY IF iArray_vtg[i_vtg] IS 1

        if (count_vtg == 2)
        {
            printf("%d\n", iArray_vtg[i_vtg]);
        }
        count_vtg = 0; // REST 'count' TO 0 FOR CHECKING THE NEXT NUMBER...
    }

    return (0);
}