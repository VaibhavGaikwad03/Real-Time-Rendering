#include <stdio.h>
int main(void)
{
    // variable declarations
    int iArray[5][3] = {{1, 2, 3}, {2, 4, 6}, {3, 6, 9}, {4, 8, 12}, {5, 10, 15}}; // IN-LINE INITIALIZATION
    int int_size;
    int iArray_size;
    int iArray_num_elements, iArray_num_rows, iArray_num_columns;

    // code
    printf("\n\n");

    int_size = sizeof(int);

    iArray_size = sizeof(iArray);
    printf("Size of two dimensional (2D) integer array is = %d\n\n", iArray_size);

    iArray_num_rows = iArray_size / sizeof(iArray[0]);
    printf("Number of rows in two dimensional (2D) integer array is = %d\n\n", iArray_num_rows);

    iArray_num_columns = sizeof(iArray[0]) / int_size;
    printf("Number of columns in two dimensional (2D) integer array is = %d\n", iArray_num_columns);

    iArray_num_elements = iArray_num_rows * iArray_num_columns;
    printf("Number of elements in two dimensional (2D) integer array is = %d\n", iArray_num_elements);

    printf("\n\n");
    printf("Elements in the 2D array:\n\n");

    // *** ARRAY INDICES BEGIN FROM 0, HENCE, 1ST ROW IS ACTUALLY OTH ROW AND 1ST COLUMN IS ACTUALLY OTH COLUMN ***

    // *** ROW 1 ***
    printf("****** Row 1 ******\n");
    printf("iArray[0][0] = %d\n", iArray[0][0]); // *** COLUMN 1 *** (0th Element)  => 1
    printf("iArray[0][1] = %d\n", iArray[0][1]); // *** COLUMN 2 *** (1st Element)  => 2
    printf("iArray[0][2] = %d\n", iArray[0][2]); // *** COLUMN 3 *** (2nd Element)  => 3
    printf("\n\n");

    // *** ROW 2 ***
    printf("****** Row 2 ******\n");
    printf("iArray[1][0] = %d\n", iArray[1][0]); // *** COLUMN 1 *** (0th Element)  => 2
    printf("iArray[1][1] = %d\n", iArray[1][1]); // *** COLUMN 2 *** (1st Element)
    printf("iArray[1][2] = %d\n", iArray[1][2]); // *** COLUMN 3 *** (2nd Element) => 6
    printf("\n\n");

    // *** ROW 3 ***
    printf("****** Row 3 ******\n");
    printf("iArray[2][0] = %d\n", iArray[2][0]); // => 3
    printf("iArray[2][1] = %d\n", iArray[2][1]); // => 6
    printf("iArray[2][2] = %d\n", iArray[2][2]); // => 9
    printf("\n\n");

    // *** ROW 4 ***
    printf("****** Row 4 ******\n");
    printf("iArray[3][0] = %d\n", iArray[3][0]); // => 4
    printf("iArray[3][1] = %d\n", iArray[3][1]); //
    printf("iArray[3][2] = %d\n", iArray[3][2]); // => 12
    printf("\n\n");

    // *** ROW 5 ***
    printf("****** Row 5 ******\n");
    printf("iArray[4][0] = %d\n", iArray[4][0]); // => 5
    printf("iArray[4][1] = %d\n", iArray[4][1]); // => 10
    printf("iArray[4][2] = %d\n", iArray[4][2]); // => 15
    printf("\n\n");

    return (0);
}