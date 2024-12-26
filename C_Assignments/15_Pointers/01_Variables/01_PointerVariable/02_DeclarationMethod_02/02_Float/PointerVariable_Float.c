#include <stdio.h>

int main(void) // variable declarations
{
    float num_vtg;
    float* ptr_vtg = NULL; // Declaration Method 1 :- 'ptr_vtg' is a variable of type 'float*'

    // code
    num_vtg = 6.9f;
    printf("\n\n");
    printf(" ****** Before ptr_vtg = &num_vtg ******\n\n");
    printf("Value of 'num_vtg' %f\n\n", num_vtg);
    printf("Address of 'num_vtg' %p\n\n", &num_vtg);
    printf("Value at address of 'num_vtg' = %f\n\n", *(&num_vtg));

    // Assigning address of variable 'num_vtg' to pointer variable 'ptr_vtg'
    //'ptr_vtg' now contains address of 'num_vtg'...hence, 'ptr_vtg' is SAME as '&num_vtg'
    ptr_vtg = &num_vtg;

    printf("\n\n");
    printf(" ****** After ptr_vtg = &num_vtg ******\n\n");
    printf("Value of 'num_vtg' %f\n\n", num_vtg);
    printf("Address of 'num_vtg' %p\n\n", ptr_vtg);
    printf("Value at address of 'num_vtg' = %f\n\n", *ptr_vtg);

    return (0);
}