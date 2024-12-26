#include <stdio.h>

int main(void)
{
    // variable declarations
    char cArray_vtg[10];
    char *ptr_cArray_vtg = NULL;
    int i_vtg;

    // code
    for (i_vtg = 0; i_vtg < 10; i_vtg++)
        cArray_vtg[i_vtg] = (char)(i_vtg + 65);

    // *** NAME OF ANY ARRAY IS ITS BASE ADDRESS ***
    // *** HENCE 'cArray_vtg' IS THE BASE ADDRESS OF ARRAY OF ARRAY cArray_vtg[] OR 'cArray_vtg' IS THE ADDRESS OF ELEMENT cArray_vtg[0] ***
    // *** ASSIGNING BASE ADDRESS OF ARRAY 'cArray_vtg[]' TO char POINTER 'ptr_cArray_vtg'

    ptr_cArray_vtg = cArray_vtg; // Ptr_cArray_vtg = &cArray_vtg[0];

    printf("\n\n");
    printf("Elements of the char array: \n\n");
    for (i_vtg = 0; i_vtg < 10; i_vtg++)
        printf("cArray_vtg[%d] = %c\n", i_vtg, cArray_vtg[i_vtg]);

    printf("\n\n");
    printf("Elements of the char array: \n\n");
    for (i_vtg = 0; i_vtg < 10; i_vtg++)
        printf("cArray_vtg[%d] = %c\t\t Address = %p\n", i_vtg, cArray_vtg[i_vtg], &cArray_vtg[i_vtg]);

    printf("\n\n");

    return (0);
}