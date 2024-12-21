#include <stdio.h>

#define NUM_ROWS 5
#define NUM_COLUMNS 3
#define DEPTH 2

int main(void)
{
    // variable declarations
    // IN-LINE INITIALIZATION
    int iArray_vtg[NUM_ROWS][NUM_COLUMNS][DEPTH] = {
        {{9, 18}, {27, 36}, {45, 54}},
        {{8, 16}, {24, 32}, {40, 48}},
        {{7, 14}, {21, 28}, {35, 42}},
        {{6, 12}, {18, 24}, {30, 36}},
        {{5, 10}, {15, 20}, {25, 30}}};

    int i_vtg, j_vtg, k_vtg;

    int iArray_1D_vtg[NUM_ROWS * NUM_COLUMNS * DEPTH]; // 5 * 3 * 2 ELEMENTS => 30 ELEMENTS IN 1D ARRAY

    // code
    //    ******   DISPLAY   3D   ARRAY   ******
    printf("\n\n");
    printf("Elements in the 3D Array : \n\n");
    for (i_vtg = 0; i_vtg < NUM_ROWS; i_vtg++)
    {
        printf("******   ROW   %d   ******\n", (i_vtg + 1));
        for (j_vtg = 0; j_vtg < NUM_COLUMNS; j_vtg++)
        {
            printf("******   COLUMN   %d   ******\n", (j_vtg + 1));
            for (k_vtg = 0; k_vtg < DEPTH; k_vtg++)
            {
                printf("iArray_vtg[%d][%d][%d] %d\n", i_vtg, j_vtg, k_vtg, iArray_vtg[i_vtg][j_vtg][k_vtg]);
            }
            printf("\n");
        }
        printf("\n");
    }

    //   ******   CONVERTING   3D   TO   1D   ******
    for (i_vtg = 0; i_vtg < NUM_ROWS; i_vtg++)
    {
        for (j_vtg = 0; j_vtg < NUM_COLUMNS; j_vtg++)
            for (k_vtg = 0; k_vtg < DEPTH; k_vtg++)
            {
                iArray_1D_vtg[(i_vtg * NUM_COLUMNS * DEPTH) + (j_vtg * DEPTH) + k_vtg] = iArray_vtg[i_vtg][j_vtg][k_vtg];
            }
    }

    //   ******   DISPLAY   1D   ARRAY   ******
    printf("\n\n\n\n");
    printf("Elements in the 1D Array : \n\n");
    for (i_vtg = 0; i_vtg < (NUM_ROWS * NUM_COLUMNS * DEPTH); i_vtg++)
    {
        printf("iArray_1D_vtg[%d] = %d\n", i_vtg, iArray_1D_vtg[i_vtg]);
    }

    return (0);
}
