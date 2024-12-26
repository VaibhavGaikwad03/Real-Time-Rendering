#include <stdio.h>

int main(void)
{
    // variable declarations
    double dArray_vtg[10];
    int i_vtg;

    // code
    for (i_vtg = 0; i_vtg < 10; i_vtg++)
        dArray_vtg[i_vtg] = (double)(i_vtg + 1) * 1.333333;

    printf("\n\n");
    printf("Elements of the double array: \n\n");
    for (i_vtg = 0; i_vtg < 10; i_vtg++)
        printf("dArray_vtg[%d] = %lf\n", i_vtg, dArray_vtg[i_vtg]);

    printf("\n\n");
    printf("Elements of the double array: \n\n");
    for (i_vtg = 0; i_vtg < 10; i_vtg++)
        printf("dArray_vtg[%d] = %lf\t\t Address = %p\n", i_vtg, dArray_vtg[i_vtg], &dArray_vtg[i_vtg]);

    printf("\n\n");

    return (0);
}