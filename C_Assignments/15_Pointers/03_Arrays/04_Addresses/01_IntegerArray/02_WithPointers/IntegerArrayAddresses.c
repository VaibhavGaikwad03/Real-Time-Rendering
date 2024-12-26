#include <stdio.h>

int main(void)
{
    // variable declarations
    int iArray_vtg[10];
    int *ptr_iArray_vtg = NULL;
    int i_vtg;

    // code
    for (i_vtg = 0; i_vtg < 10; i_vtg++)
        iArray_vtg[i_vtg] = (i_vtg + 1) * 3;

    // *** NAME OF ANY ARRAY IS ITS BASE ADDRESS ***
    // *** HENCE 'iArray_vtg' IS THE BASE ADDRESS OF ARRAY OF ARRAY iArray_vtg[] OR 'iArray_vtg' IS THE ADDRESS OF ELEMENT iArray_vtg[0] ***
    // *** ASSIGNING BASE ADDRESS OF ARRAY 'iArray_vtg[]' TO INTEGER POINTER 'ptr_iArray_vtg'

    ptr_iArray_vtg = iArray_vtg; // Ptr_iArray_vtg = &iArray_vtg[0];

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