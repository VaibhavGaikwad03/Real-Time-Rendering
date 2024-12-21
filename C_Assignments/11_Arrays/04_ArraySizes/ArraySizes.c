#include <stdio.h>

int main(void)
{
    // variable declaration
    int iArray_One_vtg[5];
    int iArray_Two_vtg[5][3];
    int iArray_Three_vtg[100][100][5];

    int num_rows_2D_vtg;
    int num_columns_2D_vtg;
    int num_rows_3D_vtg;
    int num_columns_3D_vtg;
    int depth_3D_vtg;

    // code
    printf("\n\n");
    printf("Size of 1-D integer array iArray_One_vtg = %llu\n", sizeof(iArray_One_vtg));
    printf("Number of elements in 1-D integer array iArray_One_vtg = %llu\n", (sizeof(iArray_One_vtg) / sizeof(int)));

    printf("\n\n");
    printf("Size of 2-D integer array iArray_Two_vtg = %llu\n", sizeof(iArray_Two_vtg));

    printf("Number rows in 2-D integer array iArray_Two_vtg = %llu\n", (sizeof(iArray_Two_vtg) / sizeof(iArray_Two_vtg[0])));
    num_rows_2D_vtg = (sizeof(iArray_Two_vtg) / sizeof(iArray_Two_vtg[0]));

    printf("Number of elements (columns) in each row in 2-D integer array iArray_Two_vtg %llu\n", (sizeof(iArray_Two_vtg[0]) / sizeof(iArray_Two_vtg[0][0])));
    num_columns_2D_vtg = (sizeof(iArray_Two_vtg[0]) / sizeof(iArray_Two_vtg[0][0]));

    printf("Number of elements in total in 2-D Array iArray_Two_vtg = %d\n", (num_rows_2D_vtg * num_columns_2D_vtg));

    printf("\n\n");

    printf("\n\n");
    printf("Size of 3-D integer array iArray_Three_vtg = %llu\n", sizeof(iArray_Three_vtg));

    printf("Number rows in 3-D integer array iArray_Three_vtg = %llu\n", (sizeof(iArray_Three_vtg) / sizeof(iArray_Three_vtg[0])));
    num_rows_3D_vtg = (sizeof(iArray_Three_vtg) / sizeof(iArray_Three_vtg[0]));

    printf("Number of elements (columns) in one row in 3-D integer array iArray_Three_vtg = %llu\n", (sizeof(iArray_Three_vtg[0]) / sizeof(iArray_Three_vtg[0][0])));
    num_columns_3D_vtg = (sizeof(iArray_Three_vtg[0]) / sizeof(iArray_Three_vtg[0][0]));

    printf("Number of elements (depth) in one column in one row in 3-D integer array iArray_Three_vtg = %llu\n", (sizeof(iArray_Three_vtg[0][0]) / sizeof(iArray_Three_vtg[0][0][0])));
    depth_3D_vtg = (sizeof(iArray_Three_vtg[0][0]) / sizeof(iArray_Three_vtg[0][0][0]));

    printf("Number of elements in total in 3-D Array iArray_Three_vtg = %d\n", (num_rows_3D_vtg * num_columns_3D_vtg * depth_3D_vtg));

    printf("\n\n");

    return (0);
}