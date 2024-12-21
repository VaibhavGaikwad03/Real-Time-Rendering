#include <stdio.h>
int main(void)
{
    // variable declarations
    int iArray[5][3] = {{1, 2, 3}, {2, 4, 6}, {3, 6, 9}, {4, 8, 12}, {5, 10, 15}}; // IN-LINE INITIALIZATION
    int int_size;
    int iArray_size;
    int iArray_num_elements, iArray_num_rows, iArray_num_columns;
    int i, j;

    // code
    printf("\n\n");

    int_size = sizeof(int);

    iArray_size = sizeof(iArray);
    printf("Size of two dimensional (2D) integer array is = %d\n\n", iArray_size);

    iArray_num_rows = iArray_size / sizeof(iArray[0]);
    printf("Number of rows in two dimensional (2D) integer array is = %d\n\n", iArray_num_rows);

    iArray_num_columns = sizeof(iArray[0]) / int_size;
    printf("Number of columns in two dimensional (2D) integer array is = %d\n\n", iArray_num_columns);

    iArray_num_elements = iArray_num_rows * iArray_num_columns;
    printf("Number of elements in two dimensional (2D) integer array is = %d\n\n", iArray_num_elements);

    printf("\n\n");
    printf("Elements in the 2D array:\n\n");
    // *** ARRAY INDICES BEGIN FROM 0, HENCE, 1ST ROW IS ACTUALLY OTH ROW AND 1ST COLUMN IS ACTUALLY OTH COLUMN ***
    for (i = 0; i < iArray_num_rows; i++)
    {
        printf("****** Row %d ******\n", (i + 1));
        for (j = 0; j < iArray_num_columns; j++)
        {
            printf("iArray[%d][%d] %d\n", i, j, iArray[i][j]);
        }
        printf("\n\n");
    }

    return (0);
}