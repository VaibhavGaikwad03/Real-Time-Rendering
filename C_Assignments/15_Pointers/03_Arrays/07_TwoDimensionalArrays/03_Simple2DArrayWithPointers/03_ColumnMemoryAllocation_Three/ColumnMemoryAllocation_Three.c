#include <stdio.h>
#include <stdlib.h>

#define NUM_ROWS 5
#define NUM_COLUMNS 5

int main(void)
{
    // variable declarations
    int *iArray_vtg[NUM_ROWS];
    int i_vtg, j_vtg;

    // code
    printf("\n\n");
    printf("********** MEMORY ALLOCATION TO 2D INTEGER ARRAY **********\n\n");
    for (i_vtg = 0; i_vtg < NUM_ROWS; i_vtg++)
    {
        // ROW 0 WILL HAVE (NUM_COLUMNS - 0) = (5 - 0) = 5 COLUMNS...
        // ROW 1 WILL HAVE (NUM_COLUMNS - 1) = (5 - 1) = 4 COLUMNS...
        // ROW 2 WILL HAVE (NUM_COLUMNS - 2) = (5 - 2) = 3 COLUMNS...
        // ROW 3 WILL HAVE (NUM_COLUMNS - 3) = (5 - 3) = 2 COLUMNS...
        // ROW 4 WILL HAVE (NUM_COLUMNS - 4) = (5 - 4) = 1 COLUMN...

        iArray_vtg[i_vtg] = (int *)malloc((NUM_COLUMNS - i_vtg) * sizeof(int));
        if (iArray_vtg[i_vtg] == NULL)
        {
            printf("FAILED TO ALLOCATE MEMORY TO ROW %d OF 2D INTEGER ARRAY !!! EXITTING NOW...\n\n", i_vtg);
            exit(0);
        }
        else
            printf("MEMORY ALLOCATION TO ROW %d OF 2D INTEGER ARRAY SUCCEEDED !!!\n\n", i_vtg);
    }

    for (i_vtg = 0; i_vtg < 5; i_vtg++)
    {
        for (j_vtg = 0; j_vtg < (NUM_COLUMNS - i_vtg); j_vtg++)
        {
            iArray_vtg[i_vtg][j_vtg] = (i_vtg * 1) + (j_vtg * 1);
        }
    }

    for (i_vtg = 0; i_vtg < 5; i_vtg++)
    {
        for (j_vtg = 0; j_vtg < (NUM_COLUMNS - i_vtg); j_vtg++)
        {
            printf("iArray[%d][%d] = %d \t At Address : %p\n", i_vtg, j_vtg, iArray_vtg[i_vtg][j_vtg], &iArray_vtg[i_vtg][j_vtg]);
        }
        printf("\n");
    }

    for (i_vtg = (NUM_ROWS - 1); i_vtg >= 0; i_vtg--)
    {
        if (iArray_vtg[i_vtg])
        {
            free(iArray_vtg[i_vtg]);
            iArray_vtg[i_vtg] = NULL;
            printf("MEMORY ALLOCATED TO ROW %d HAS BEEN SUCCESSFULLY FREED !!!\n\n", i_vtg);
        }
    }

    return (0);
}