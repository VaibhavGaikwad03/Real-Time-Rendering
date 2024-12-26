#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // variable declarations
    int **ptr_iArray_vtg = NULL; // A pointer-to-pointer to integer ... but can also hold base address of a 2D Array which will can have any number of rows and any number of columns ...
    int i_vtg, j_vtg;
    int num_rows_vtg, num_columns_vtg;

    // code

    // *** ACCEPT NUMBER OF ROWS 'num_rows' FROM USER ***
    printf("\n\n");
    printf("Enter number of rows: ");
    scanf("%d", &num_rows_vtg);

    // *** ACCEPT NUMBER OF COLUMNS 'num_columns' FROM USER ***
    printf("\n\n");
    printf("Enter number of columns: ");
    scanf("%d", &num_columns_vtg);

    // *** ALLOCATING MEMORY TO ID ARRAY CONSISTING OF BASE ADDRESS OF ROWS ***
    printf("\n\n");
    printf("********** MEMORY ALLOCATION TO 2D INTEGER ARRAY **********\n\n");
    ptr_iArray_vtg = (int **)malloc(num_rows_vtg * sizeof(int *));
    if (ptr_iArray_vtg == NULL)
    {
        printf("Failed to allocate memory to %d rows of 2D integer array! Exiting now...\n\n", num_rows_vtg);
        exit(0);
    }
    else
        printf("Memory allocation to %d rows of 2D integer array succeeded!\n\n", num_rows_vtg);

    // *** ALLOCATING MEMORY TO EACH ROW WHICH ISA ID ARRAY CONTAINING CONSISTING OF COLUMNS WHICH CONTAIN THE ACTUAL INTEGERS ***
    for (int i_vtg = 0; i_vtg < num_rows_vtg; i_vtg++)
    {
        ptr_iArray_vtg[i_vtg] = (int *)malloc(num_columns_vtg * sizeof(int)); // ALLOCATING MEMORY (Number Of Columns * size of 'int') TO ROW 'i'
        if (ptr_iArray_vtg[i_vtg] == NULL)                                    // ROW 'i' MEMORY ALLOCATED ?
        {
            printf("Failed to allocate memory to columns of row %d of 2D integer array! Exiting now...\n\n", i_vtg);
            exit(0);
        }
        else
            printf("Memory allocation to columns of row %d of 2D integer array succeeded!\n\n", i_vtg);
    }

    // *** FILLING UP VALUES ***
    for (int i_vtg = 0; i_vtg < num_rows_vtg; i_vtg++)
    {
        for (int j_vtg = 0; j_vtg < num_columns_vtg; j_vtg++)
            ptr_iArray_vtg[i_vtg][j_vtg] = (i_vtg * 1) + (j_vtg * 1); // can also use : *(*  (ptr_iArray + i) + j) = (i* 1) + (j* 1)
    }

    // *** DISPLAYING VALUES ***
    for (int i_vtg = 0; i_vtg < num_rows_vtg; i_vtg++)
    {
        printf("Base address of row %d: ptr_iArray[%d] = %p \t At address: %p\n", i_vtg, i_vtg, ptr_iArray_vtg[i_vtg], &ptr_iArray_vtg[i_vtg]);
    }

    printf("\n\n");

    for (i_vtg = 0; i_vtg < num_rows_vtg; i_vtg++)
    {
        for (j_vtg = 0; j_vtg < num_columns_vtg; j_vtg++)
        {
            printf("ptr_iArray[%d][%d] = %d \t At address: %p\n", i_vtg, j_vtg, ptr_iArray_vtg[i_vtg][j_vtg], &ptr_iArray_vtg[i_vtg][j_vtg]); // can also use *(*  (ptr_iArray + i) + j) for value and *(ptr_iArray + i) + j for address ...
        }
        printf("\n");
    }

    // *** FREEING MEMORY ALLOCATED TO EACH ROW ***
    for (int i_vtg = (num_rows_vtg - 1); i_vtg >= 0; i_vtg--)
    {
        if (ptr_iArray_vtg[i_vtg])
        {
            free(ptr_iArray_vtg[i_vtg]);
            ptr_iArray_vtg[i_vtg] = NULL;
            printf("Memory allocated to row %d has been successfully freed!\n\n", i_vtg);
        }
    }

    // *** FREEING MEMORY ALLOCATED TO  1D ARRAY CONSISTING OF BASE ADDRESSES OF ROWS ***
    if (ptr_iArray_vtg)
    {
        free(ptr_iArray_vtg);
        ptr_iArray_vtg = NULL;
        printf("Memory allocated to ptr_iArray has been successfully freed!\n");
    }

    return (0);
}