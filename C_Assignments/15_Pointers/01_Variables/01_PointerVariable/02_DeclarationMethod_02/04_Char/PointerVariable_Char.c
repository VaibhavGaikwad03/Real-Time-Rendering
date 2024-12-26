#include <stdio.h>

int main(void) // variable declarations
{
    char ch_vtg;
    char* ptr_vtg = NULL; // Declaration Method 1 :- 'ptr_vtg' is a variable of type 'char*'

    // code
    ch_vtg = 'V';
    printf("\n\n");
    printf(" ****** Before ptr_vtg = &ch_vtg ******\n\n");
    printf("Value of 'ch_vtg' %c\n\n", ch_vtg);
    printf("Address of 'ch_vtg' %p\n\n", &ch_vtg);
    printf("Value at address of 'ch_vtg' = %c\n\n", *(&ch_vtg));

    // Assigning address of variable 'ch_vtg' to pointer variable 'ptr_vtg'
    //'ptr_vtg' now contains address of 'ch_vtg'...hence, 'ptr_vtg' is SAME as '&ch_vtg'
    ptr_vtg = &ch_vtg;

    printf("\n\n");
    printf(" ****** After ptr_vtg = &ch_vtg ******\n\n");
    printf("Value of 'ch_vtg' %c\n\n", ch_vtg);
    printf("Address of 'ch_vtg' %p\n\n", ptr_vtg);
    printf("Value at address of 'ch_vtg' = %c\n\n", *ptr_vtg);

    return (0);
}