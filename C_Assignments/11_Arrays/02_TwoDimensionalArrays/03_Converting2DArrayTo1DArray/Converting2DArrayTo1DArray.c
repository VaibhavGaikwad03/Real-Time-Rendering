#include <stdio.h>

#define NUM_ROWS 5
#define NUM_COLUMNS 3

int main(void)
{
    // variable declarations
    int iArray_2D[NUM_ROWS][NUM_COLUMNS]; // TOTAL NUMBER OF ELEMENTS = NUM_ROWS * NUM_COLUMNS
    int iArray_1D[NUM_ROWS * NUM_COLUMNS];

    int i, j;
    int num;

    // code
    printf("Enter elements of your choice to fill up the integer 2D array: \n");
    for (i = 0; i < NUM_ROWS; i++)
    {
        printf("For row number %d: \n", (i + 1));
        for (j = 0; j < NUM_COLUMNS; j++)
        {
            printf("Enter element number %d: \n", (j + 1));
            scanf("%d", &num);
            iArray_2D[i][j] = num;
            printf("iArray_2D[%d][%d] %d\n", i, j, iArray_2D[i][j]);
        }
        printf("\n\n");
    }

    // *** DISPLAY OF 2D ARRAY ***
    printf("\n\n");
    printf("Two-dimensional (2D) array of integers: \n\n");
    for (i = 0; i < NUM_ROWS; i++)
    {
        printf("****** Row %d ******\n", (i + 1));
        for (j = 0; j < NUM_COLUMNS; j++)
        {
            printf("iArray_2D[%d][%d] = %d\n", i, j, iArray_2D[i][j]);
        }
        printf("\n\n");
    }

    // *** CONVERTING 2D INTEGER ARRAY TO 1D INTEGER ARRAY ***
    for (i = 0; i < NUM_ROWS; i++)
    {
        for (j = 0; j < NUM_COLUMNS; j++)
        {
            iArray_1D[(i * NUM_COLUMNS) + j] = iArray_2D[i][j];
        }
    }

    // *** PRINTING 1D ARRAY ***
    printf("\n\n");
    printf("One-dimensional (1D) array of integers: \n\n");
    for (i = 0; i < (NUM_ROWS * NUM_COLUMNS); i++)
    {
        printf("iArray_1D[%d] = %d\n", i, iArray_1D[i]);
    }

    printf("\n\n");

    return (0);
}