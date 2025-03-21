#include <stdio.h>
#include <stdlib.h>

#define NUM_ROWS 5
#define NUM_COLUMNS_ONE 3
#define NUM_COLUMNS_TWO 8

int main(void)
{
    // variable declarations
    int *iArray_vtg[NUM_ROWS]; // A 2D Array which will have 5 rows and number of
                               // columns can be decided later on ...
    int i_vtg, j_vtg;

    // ONE (ALLOCATING MEMORY FOR AN ARRAY OF 3 INTEGERS PER ROW)
    printf("\n\n");
    printf("********** FIRST MEMORY ALLOCATION TO 2D INTEGER ARRAY **********\n\n");
    for (i_vtg = 0; i_vtg < NUM_ROWS; i_vtg++)
    {
        iArray_vtg[i_vtg] = (int *)malloc(NUM_COLUMNS_ONE * sizeof(int));
        if (iArray_vtg[i_vtg] == NULL)
        {
            printf("FAILED TO ALLOCATE MEMORY TO ROW %d OF 2D INTEGER ARRAY !!! EXITING NOW...\n\n", i_vtg);
            exit(0);
        }
        else
        {
            printf("MEMORY ALLOCATION TO ROW %d OF 2D INTEGER ARRAY SUCCEEDED !!!\n\n", i_vtg);
        }
    }

    // ASSIGNING VALUES TO 2D ARRAY ...
    for (i_vtg = 0; i_vtg < NUM_ROWS; i_vtg++)
    {
        for (j_vtg = 0; j_vtg < NUM_COLUMNS_ONE; j_vtg++)
        {
            iArray_vtg[i_vtg][j_vtg] = (i_vtg + 1) * (j_vtg + 1);
        }
    }

    // DISPLAYING 2D ARRAY ...
    printf("\n\n");
    printf("DISPLAYING 2D ARRAY : \n\n");
    for (i_vtg = 0; i_vtg < NUM_ROWS; i_vtg++)
    {
        for (j_vtg = 0; j_vtg < NUM_COLUMNS_ONE; j_vtg++)
        {
            printf("iArray[%d][%d] = %d\n", i_vtg, j_vtg, iArray_vtg[i_vtg][j_vtg]);
        }
        printf("\n\n");
    }
    printf("\n\n");

    // FREEING MEMORY ASSIGNED TO 2D ARRAY (MUST BE DONE IN REVERSE ORDER)
    for (i_vtg = (NUM_ROWS - 1); i_vtg >= 0; i_vtg--)
    {
        free(iArray_vtg[i_vtg]);
        iArray_vtg[i_vtg] = NULL;
        printf("MEMORY ALLOCATED TO ROW %d OF 2D INTEGER ARRAY HAS BEEN SUCCESSFULLY FREED !!!\n\n", i_vtg);
    }

    // TWO (ALLOCATING MEMORY FOR AN ARRAY OF 8 INTEGERS PER ROW)
    printf("\n\n");
    printf("********** SECOND MEMORY ALLOCATION TO 2D INTEGER ARRAY **********\n\n");
    for (i_vtg = 0; i_vtg < NUM_ROWS; i_vtg++)
    {
        iArray_vtg[i_vtg] = (int *)malloc(NUM_COLUMNS_TWO * sizeof(int));
        if (iArray_vtg[i_vtg] == NULL)
        {
            printf("FAILED TO ALLOCATE MEMORY TO ROW %d OF 2D INTEGER ARRAY !!! EXITING NOW...\n\n", i_vtg);
            exit(0);
        }
        else
        {
            printf("MEMORY ALLOCATION TO ROW %d OF 2D INTEGER ARRAY SUCCEEDED !!!\n\n", i_vtg);
        }
    }

    // ASSIGNING VALUES TO 2D ARRAY ...
    for (i_vtg = 0; i_vtg < NUM_ROWS; i_vtg++)
    {
        for (j_vtg = 0; j_vtg < NUM_COLUMNS_TWO; j_vtg++)
        {
            iArray_vtg[i_vtg][j_vtg] = (i_vtg + 1) * (j_vtg + 1);
        }
    }

    // DISPLAYING 2D ARRAY ...
    printf("\n\n");
    printf("DISPLAYING 2D ARRAY : \n\n");
    for (i_vtg = 0; i_vtg < NUM_ROWS; i_vtg++)
    {
        for (j_vtg = 0; j_vtg < NUM_COLUMNS_TWO; j_vtg++)
        {
            printf("iArray[%d][%d] = %d\n", i_vtg, j_vtg, iArray_vtg[i_vtg][j_vtg]);
        }
        printf("\n\n");
    }
    printf("\n\n");

    // FREEING MEMORY ASSIGNED TO 2D ARRAY (MUST BE DONE IN REVERSE ORDER)
    for (i_vtg = (NUM_ROWS - 1); i_vtg >= 0; i_vtg--)
    {
        free(iArray_vtg[i_vtg]);
        iArray_vtg[i_vtg] = NULL;
        printf("MEMORY ALLOCATED TO ROW %d OF 2D INTEGER ARRAY HAS BEEN SUCCESSFULLY FREED !!!\n\n", i_vtg);
    }

    return (0);
}