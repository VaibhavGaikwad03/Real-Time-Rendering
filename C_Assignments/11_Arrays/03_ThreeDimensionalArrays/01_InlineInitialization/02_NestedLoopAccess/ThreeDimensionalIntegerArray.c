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
    int i_vtg, j_vtg, k_vtg;

    // code
    printf("\n\n");

    int_size_vtg = sizeof(int);

    iArray_size_vtg = sizeof(iArray_vtg);
    printf("Size of three dimensional (3D) integer array is = %d\n\n", iArray_size_vtg);

    iArray_width_vtg = iArray_size_vtg / sizeof(iArray_vtg[0]);
    printf("Number of rows (width) in three dimensional (3D) integer array is =  %d\n\n", iArray_width_vtg);

    iArray_height_vtg = sizeof(iArray_vtg[0]) / sizeof(iArray_vtg[0][0]);
    printf("Number of columns (height) in three dimensional (3D) integer array is = %d\n\n", iArray_height_vtg);
    
    iArray_depth_vtg = sizeof(iArray_vtg[0][0]) / int_size_vtg;
    printf("Depth in three dimensional (3D) integer array is = %d\n\n", iArray_depth_vtg);
    
    iArray_num_elements_vtg = iArray_width_vtg * iArray_height_vtg * iArray_depth_vtg;
    printf("Number of elements in three dimensional (3D) integer array is = %d\n\n", iArray_num_elements_vtg);
    
    printf("\n\n");
    printf("Elements in integer 3D array :   \n\n");

    for (i_vtg = 0; i_vtg < iArray_width_vtg; i_vtg++)
    {
        printf("****** Row %d ******\n", (i_vtg + 1));
        for (j_vtg = 0; j_vtg < iArray_height_vtg; j_vtg++)
        {
            printf("****** Column %d ******\n", (j_vtg + 1));
            for (k_vtg = 0; k_vtg < iArray_depth_vtg; k_vtg++)
            {
                printf("iArray[%d][%d][%d] %d\n", i_vtg, j_vtg, k_vtg, iArray_vtg[i_vtg][j_vtg][k_vtg]);
            }
            printf("\n");
        }
        printf("\n\n");
    }

    return (0);
}