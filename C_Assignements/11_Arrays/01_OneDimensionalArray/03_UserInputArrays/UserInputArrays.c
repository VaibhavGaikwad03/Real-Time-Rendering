#include <stdio.h>

// MACRO CONSTANT USED AS ARRAY SIZE IN SUBSCRIPT AND AS ARRAY LENGTH.
// HENCE, THIS PROGRAM'S ARRAYS' SIZES CAN BE SIMPLY CHANGED BY CHANGING THESE FOLLOWING 3 GLOBAL MACRO CONSTANT VALUES, BEFORE COMPILING, LINKING AND EXECUTING THE PROGRAM !!!

#define INT_ARRAY_NUM_ELEMENTS 5
#define FLOAT_ARRAY_NUM_ELEMENTS 3
#define CHAR_ARRAY_NUM_ELEMENTS 15

int main(void) // variable declarations
{
    int iArray_vtg[INT_ARRAY_NUM_ELEMENTS];
    float fArray_vtg[FLOAT_ARRAY_NUM_ELEMENTS];
    char cArray_vtg[CHAR_ARRAY_NUM_ELEMENTS];
    int i_vtg, num_vtg;

    // code
    //  ********* ARRAY ELEMENTS INPUT **********
    printf("\n\n");
    printf("Enter elements for 'integer' array: \n");
    for (i_vtg = 0; i_vtg < INT_ARRAY_NUM_ELEMENTS; i_vtg++)
        scanf("%d", &iArray_vtg[i_vtg]);

    printf("\n\n");
    printf("Enter elements for 'floating-point' array: \n");
    for (i_vtg = 0; i_vtg < FLOAT_ARRAY_NUM_ELEMENTS; i_vtg++)
        scanf("%f", &fArray_vtg[i_vtg]);

    printf("\n\n");
    printf("Enter elements for 'character' array: \n");
    for (i_vtg = 0; i_vtg < CHAR_ARRAY_NUM_ELEMENTS; i_vtg++)
    {
        cArray_vtg[i_vtg] = getch();
        printf("%c\n", cArray_vtg[i_vtg]);
    }

    // ********** ARRAY ELEMENTS OUTPUT **********
    printf("\n\n");
    printf("Integer array entered by you: \n\n");
    for (i_vtg = 0; i_vtg < INT_ARRAY_NUM_ELEMENTS; i_vtg++)
        printf("%d\n", iArray_vtg[i_vtg]);

    printf("\n\n");
    printf("Floating-point array entered by you: \n\n");
    for (i_vtg = 0; i_vtg < FLOAT_ARRAY_NUM_ELEMENTS; i_vtg++)
        printf("%f\n", fArray_vtg[i_vtg]);

    printf("\n\n");
    printf("Character array entered by you: \n\n");
    for (i_vtg = 0; i_vtg < CHAR_ARRAY_NUM_ELEMENTS; i_vtg++)
        printf("%c\n", cArray_vtg[i_vtg]);

    return (0);
}