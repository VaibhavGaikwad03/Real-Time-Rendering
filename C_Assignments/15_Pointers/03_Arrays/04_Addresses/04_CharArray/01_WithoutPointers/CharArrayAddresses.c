#include <stdio.h>

int main(void)
{
    // variable declarations
    char cArray_vtg[10];
    int i_vtg;

    // code
    for (i_vtg = 0; i_vtg < 10; i_vtg++)
        cArray_vtg[i_vtg] = (char)(i_vtg + 65);

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