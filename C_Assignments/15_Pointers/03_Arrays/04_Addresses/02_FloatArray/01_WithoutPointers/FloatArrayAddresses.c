#include <stdio.h>

int main(void)
{
    // variable declarations
    float fArray_vtg[10];
    int i_vtg;

    // code
    for (i_vtg = 0; i_vtg < 10; i_vtg++)
        fArray_vtg[i_vtg] = (float)(i_vtg + 1) * 1.5f;

    printf("\n\n");
    printf("Elements of the float array: \n\n");
    for (i_vtg = 0; i_vtg < 10; i_vtg++)
        printf("fArray_vtg[%d] = %f\n", i_vtg, fArray_vtg[i_vtg]);

    printf("\n\n");
    printf("Elements of the float array: \n\n");
    for (i_vtg = 0; i_vtg < 10; i_vtg++)
        printf("fArray_vtg[%d] = %f\t\t Address = %p\n", i_vtg, fArray_vtg[i_vtg], &fArray_vtg[i_vtg]);

    printf("\n\n");

    return (0);
}