#include <stdio.h>

#define num_vtg_ELEMEMTS 10

int main(void)
{
    // variable declarations
    int iArray_vtg[num_vtg_ELEMEMTS];
    int i_vtg, num_vtg, sum_vtg = 0;

    // code
    printf("\n\n");
    printf("Enter integer elements for array: \n\n");
    for (i_vtg = 0; i_vtg < num_vtg_ELEMEMTS; i_vtg++)
    {
        scanf("%d", &num_vtg);
        iArray_vtg[i_vtg] = num_vtg;
    }

    for (i_vtg = 0; i_vtg < num_vtg_ELEMEMTS; i_vtg++)
    {
        sum_vtg = sum_vtg + iArray_vtg[i_vtg];
    }

    printf("\n\n");
    printf("Sum_vtg of all elements of array = %d\n\n", sum_vtg);

    return (0);
}