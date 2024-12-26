#include <stdio.h>

int main(void)
{
    // variable declarations
    float fArray_vtg[10];
    float *ptr_fArray_vtg = NULL;
    int i_vtg;

    // code
    for (i_vtg = 0; i_vtg < 10; i_vtg++)
        fArray_vtg[i_vtg] = (float)(i_vtg + 1) * 1.5f;

    // *** NAME OF ANY ARRAY IS ITS BASE ADDRESS ***
    // *** HENCE 'fArray_vtg' IS THE BASE ADDRESS OF ARRAY OF ARRAY fArray_vtg[] OR 'fArray_vtg' IS THE ADDRESS OF ELEMENT fArray_vtg[0] ***
    // *** ASSIGNING BASE ADDRESS OF ARRAY 'fArray_vtg[]' TO float POINTER 'ptr_fArray_vtg'

    ptr_fArray_vtg = fArray_vtg; // Ptr_fArray_vtg = &fArray_vtg[0];

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