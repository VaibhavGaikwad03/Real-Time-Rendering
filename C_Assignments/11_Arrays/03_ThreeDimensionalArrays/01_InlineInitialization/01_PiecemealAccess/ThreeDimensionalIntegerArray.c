#include <stdio.h>
int main(void)
{
    // variable declarations
    // IN-LINE INITIALIZATION
    int iArray_vtg[5][3][2] = {{{9, 18}, {27, 36}, {45, 54}},
                               {{8, 16}, {24, 32}, {40, 48}},
                               {{7, 14}, {21, 28}, {35, 42}},
                               {{6, 12}, {18, 24}, {30, 36}},
                               {{5, 10}, {15, 20}, {25, 30}}};

    int int_size_vtg;
    int iArray_size_vtg;
    int iArray_num_elements_vtg, iArray_width_vtg, iArray_height_vtg, iArray_depth_vtg;

    // code
    printf("\n\n");

    int_size_vtg = sizeof(int);

    iArray_size_vtg = sizeof(iArray_vtg);

    printf("Size of three dimensional (3D) integer array is = %d\n\n", iArray_size_vtg);

    iArray_width_vtg = iArray_size_vtg / sizeof(iArray_vtg[0]);
    printf("Number of rows (width) in three dimensional (3D) integer array is = %d\n\n", iArray_width_vtg);

    iArray_height_vtg = sizeof(iArray_vtg[0]) / sizeof(iArray_vtg[0][0]);
    printf("Number of columns (height) in three dimensional (3D) integer array is = %d\n\n", iArray_height_vtg);

    iArray_depth_vtg = sizeof(iArray_vtg[0][0]) / int_size_vtg;
    printf("Depth in three dimensional (3D) integer array is = %d\n\n", iArray_depth_vtg);

    iArray_num_elements_vtg = iArray_width_vtg * iArray_height_vtg * iArray_depth_vtg;
    printf("Number of elements in three dimensional (3D) integer array is = %d\n\n", iArray_num_elements_vtg);

    printf("\n\n");
    printf("Elements in integer 3D array:\n\n");

    //   ***   PIECE-MEAL   DISPLAY   ***
    //   ******   ROW 1   ******
    printf("******   Row 1   ******\n");
    printf("******   Column 1   ******\n");
    printf("iArray_vtg[0][0][0] = %d\n", iArray_vtg[0][0][0]);
    printf("iArray_vtg[0][0][1] = %d\n", iArray_vtg[0][0][1]);
    printf("\n");

    printf("******   Column 2   ******\n");
    printf("iArray_vtg[0][1][0] = %d\n", iArray_vtg[0][1][0]);
    printf("iArray_vtg[0][1][1] = %d\n", iArray_vtg[0][1][1]);
    printf("\n");

    printf("******   Column 3   ******\n");
    printf("iArray_vtg[0][2][0] = %d\n", iArray_vtg[0][2][0]);
    printf("iArray_vtg[0][2][1] = %d\n", iArray_vtg[0][2][1]);
    printf("\n\n");

    //   ******   ROW 2   ******
    printf("******   Row 2   ******\n");
    printf("******   Column 1   ******\n");
    printf("iArray_vtg[1][0][0] = %d\n", iArray_vtg[1][0][0]);
    printf("iArray_vtg[1][0][1] = %d\n", iArray_vtg[1][0][1]);
    printf("\n");

    printf("******   Column 2   ******\n");
    printf("iArray_vtg[1][1][0] = %d\n", iArray_vtg[1][1][0]);
    printf("iArray_vtg[1][1][1] = %d\n", iArray_vtg[1][1][1]);
    printf("\n");

    printf("******   Column 3   ******\n");
    printf("iArray_vtg[1][2][0] = %d\n", iArray_vtg[1][2][0]);
    printf("iArray_vtg[1][2][1] = %d\n", iArray_vtg[1][2][1]);
    printf("\n\n");

    //   ******   ROW 3   ******
    printf("******   Row 3   ******\n");
    printf("******   Column 1   ******\n");
    printf("iArray_vtg[2][0][0] = %d\n", iArray_vtg[2][0][0]);
    printf("iArray_vtg[2][0][1] = %d\n", iArray_vtg[2][0][1]);
    printf("\n");

    printf("******   Column 2   ******\n");
    printf("iArray_vtg[2][1][0] = %d\n", iArray_vtg[2][1][0]);
    printf("iArray_vtg[2][1][1] = %d\n", iArray_vtg[2][1][1]);
    printf("\n");

    printf("******   Column 3   ******\n");
    printf("iArray_vtg[2][2][0] = %d\n", iArray_vtg[2][2][0]);
    printf("iArray_vtg[2][2][1] = %d\n", iArray_vtg[2][2][1]);
    printf("\n\n");

    //   ******   ROW 4   ******
    printf("******   Row 4   ******\n");
    printf("******   Column 1   ******\n");
    printf("iArray_vtg[3][0][0] = %d\n", iArray_vtg[3][0][0]);
    printf("iArray_vtg[3][0][1] = %d\n", iArray_vtg[3][0][1]);
    printf("\n");

    printf("******   Column 2   ******\n");
    printf("iArray_vtg[3][1][0] = %d\n", iArray_vtg[3][1][0]);
    printf("iArray_vtg[3][1][1] = %d\n", iArray_vtg[3][1][1]);
    printf("\n");

    printf("******   Column 3   ******\n");
    printf("iArray_vtg[3][2][0] = %d\n", iArray_vtg[3][2][0]);
    printf("iArray_vtg[3][2][1] = %d\n", iArray_vtg[3][2][1]);
    printf("\n\n");

    //   ******   ROW 5   ******
    printf("******   Row 5   ******\n");
    printf("******   Column 1   ******\n");
    printf("iArray_vtg[4][0][0] = %d\n", iArray_vtg[4][0][0]);
    printf("iArray_vtg[4][0][1] = %d\n", iArray_vtg[4][0][1]);
    printf("\n");

    printf("******   Column 2   ******\n");
    printf("iArray_vtg[4][1][0] = %d\n", iArray_vtg[4][1][0]);
    printf("iArray_vtg[4][1][1] = %d\n", iArray_vtg[4][1][1]);
    printf("\n");

    printf("******   Column 3   ******\n");
    printf("iArray_vtg[4][2][0] = %d\n", iArray_vtg[4][2][0]);
    printf("iArray_vtg[4][2][1] = %d\n", iArray_vtg[4][2][1]);
    printf("\n\n");

    return (0);
}
