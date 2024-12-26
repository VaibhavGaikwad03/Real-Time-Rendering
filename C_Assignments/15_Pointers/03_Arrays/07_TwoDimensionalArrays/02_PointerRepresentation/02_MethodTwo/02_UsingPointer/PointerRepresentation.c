#include <stdio.h>
#include <stdlib.h>

#define NUM_ROWS 5
#define NUM_COLUMNS 3

int main(void)
{
    // variable declarations
    int i_vtg, j_vtg;
    int **ptr_iArray_vtg = NULL;

    // code
    // *** EVERY ROW OFA 2D ARRAY IS AN INTEGER ARRAY ITSELF COMPRISING OF 'NUM_COLUMNS' INTEGER ELEMENTS ***
    // *** THERE ARE 5 ROWS AND 3 COLUMNS IN A 2D INTEGER ARRAY. EACH OF THE 5 ROWS IS A ID ARRAY OF 3 INTEGERS.
    // *** HENCE, EACH OF THESE 5 ROWS THEMSELVES BEING ARRAYS, WILL BE THE BASE ADDRESSES OF THEIR RESPECTIVE ROWS ***
    printf("\n\n");

    // *** MEMORY ALLOCATION ***
    ptr_iArray_vtg = (int **)malloc(NUM_ROWS * sizeof(int *)); // ptr_iArray_vtg is the name and base address of 1D Array containing 5 integer pointers to 5 integer arrays ... so it is an array containing elements of data type (int *)
    if (ptr_iArray_vtg == NULL)
    {
        printf("Memory allocation to the 1D array of base addresses of %d rows failed! Exiting now...\n\n", NUM_ROWS);
        exit(0);
    }
    else
        printf("Memory allocation to the 1D array of base addresses of %d rows has succeeded!\n\n", NUM_ROWS);

    // *** ALLOCATING MEMORY TO EACH ROW ***
    for (i_vtg = 0; i_vtg < NUM_ROWS; i_vtg++)
    {
        ptr_iArray_vtg[i_vtg] = (int *)malloc(NUM_COLUMNS * sizeof(int)); // ptr_iArray_vtg[i_vtg] is the base address of ith row ...
        if (ptr_iArray_vtg[i_vtg] == NULL)
        {
            printf("Memory allocation to the columns of row %d failed! Exiting now...\n\n", i_vtg);
            exit(0);
        }
        else
            printf("Memory allocation to the columns of row %d has succeeded!\n\n", i_vtg);
    }

    // *** ASSIGNING VALUES ***
    for (i_vtg = 0; i_vtg < NUM_ROWS; i_vtg++)
    {
        for (j_vtg = 0; j_vtg < NUM_COLUMNS; j_vtg++)
            *(*(ptr_iArray_vtg + i_vtg) + j_vtg) = (i_vtg + 1) * (j_vtg + 1); // ptr_iArray_vtg[i_vtg][j_vtg] = v (i_vtg + 1) * (j_vtg + 1);
    }

    // *** DISPLAYING VALUES ***
    printf("\n\n");
    printf("2D integer array elements along with addresses:\n\n");
    for (i_vtg = 0; i_vtg < NUM_ROWS; i_vtg++)
    {
        for (j_vtg = 0; j_vtg < NUM_COLUMNS; j_vtg++)
            printf("ptr_iArray_Row[%d][%d] %d  \t\t At address &ptr_iArray_Row[%d][%d] : %p\n", i_vtg, j_vtg, ptr_iArray_vtg[i_vtg][j_vtg], i_vtg, j_vtg, &ptr_iArray_vtg[i_vtg][j_vtg]);
        printf("\n\n");
    }

    // *** FREEING ALLOCATED MEMORY ***
    // *** FREEING MEMORY OF EACH ROW ***
    for (i_vtg = (NUM_ROWS - 1); i_vtg >= 0; i_vtg--)
    {
        if (*(ptr_iArray_vtg + i_vtg)) // if(ptr_iArray_vtg[i_vtg])
        {
            free(*(ptr_iArray_vtg + i_vtg));  // free(ptr_iArray_vtg[i_vtg])
            *(ptr_iArray_vtg + i_vtg) = NULL; // ptr_iArray_vtg[i_vtg] = NULL;
            printf("Memory allocated to row %d has been successfully freed!\n\n", i_vtg);
        }
    }

    // *** FREEING MEMORY OF ptr_iArray_vtg WHICH IS THE ARRAY OF 5 INTEGER POINTERS ... THAT IT, IT IS AN ARRAY HAVING 5 INTEGER ADDRESSES (TYPE int **)
    if (ptr_iArray_vtg)
    {
        free(ptr_iArray_vtg);
        ptr_iArray_vtg = NULL;
        printf("Memory allocated to ptr_iArray_vtg has been successfully freed!\n");
    }

    return (0);
}