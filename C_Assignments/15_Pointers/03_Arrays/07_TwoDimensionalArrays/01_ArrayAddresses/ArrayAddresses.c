#include <stdio.h>
#include <stdlib.h>

#define NUM_ROWS 5
#define NUM_COLUMNS 3

int main(void)
{
    // variable declarations
    int iArray_vtg[NUM_ROWS][NUM_COLUMNS];
    int i_vtg, j_vtg;

    // code
    for (i_vtg = 0; i_vtg < NUM_ROWS; i_vtg++)
    {
        for (j_vtg = 0; j_vtg < NUM_COLUMNS; j_vtg++)
            iArray_vtg[i_vtg][j_vtg] = (i_vtg + 1) * (j_vtg + 1);
    }

    printf("\n\n");
    printf("2D integer array elements along with addresses: \n\n");
    for (i_vtg = 0; i_vtg < NUM_ROWS; i_vtg++)
    {
        for (j_vtg = 0; j_vtg < NUM_COLUMNS; j_vtg++)
            printf("iArray_vtg[%d][%d] = %d\t\t at address: %p\n", i_vtg, j_vtg, iArray_vtg[i_vtg][j_vtg], &iArray_vtg[i_vtg][j_vtg]);
        printf("\n");
    }

    return (0);
}