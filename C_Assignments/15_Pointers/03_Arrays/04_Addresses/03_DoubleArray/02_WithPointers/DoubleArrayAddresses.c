#include <stdio.h>

int main(void)
{
    // variable declarations
    double dArray_vtg[10];
    double *ptr_dArray_vtg = NULL;
    int i_vtg;

    // code
    for (i_vtg = 0; i_vtg < 10; i_vtg++)
        dArray_vtg[i_vtg] = (double)(i_vtg + 1) * 1.33333;

    // *** NAME OF ANY ARRAY IS ITS BASE ADDRESS ***
    // *** HENCE 'dArray_vtg' IS THE BASE ADDRESS OF ARRAY OF ARRAY dArray_vtg[] OR 'dArray_vtg' IS THE ADDRESS OF ELEMENT dArray_vtg[0] ***
    // *** ASSIGNING BASE ADDRESS OF ARRAY 'dArray_vtg[]' TO double POINTER 'ptr_dArray_vtg'

    ptr_dArray_vtg = dArray_vtg; // Ptr_dArray_vtg = &dArray_vtg[0];

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