#include <stdio.h>

int main(void)
{
    // variable declarations
    int iArray_vtg[10];
    int i_vtg;

    // code
    for (i_vtg = 0; i_vtg < 10; i_vtg++)
        iArray_vtg[i_vtg] = (i_vtg + 1) * 3;

    printf("\n\n");
    printf("Elements of the integer array: \n\n");
    for (i_vtg = 0; i_vtg < 10; i_vtg++)
        printf("iArray_vtg[%d] = %d\n", i_vtg, iArray_vtg[i_vtg]);

    printf("\n\n");
    printf("Elements of the integer array: \n\n");
    for (i_vtg = 0; i_vtg < 10; i_vtg++)
        printf("iArray_vtg[%d] = %d\t\t Address = %p\n", i_vtg, iArray_vtg[i_vtg], &iArray_vtg[i_vtg]);

    printf("\n\n");

    return (0);
}