#include <stdio.h>

int main(void) // variable declarations
{
    double num_vtg;
    double* ptr_vtg = NULL; // Declaration Method 1 :- 'ptr_vtg' is a variable of type 'double*'

    // code
    num_vtg = 2.33323423;
    printf("\n\n");
    printf(" ****** Before ptr_vtg = &num_vtg ******\n\n");
    printf("Value of 'num_vtg'%lf\n\n", num_vtg);
    printf("Address of 'num_vtg' %p\n\n", &num_vtg);
    printf("Value at address of 'num_vtg' =%lf\n\n", *(&num_vtg));

    // Assigning address of variable 'num_vtg' to pointer variable 'ptr_vtg'
    //'ptr_vtg' now contains address of 'num_vtg'...hence, 'ptr_vtg' is SAME as '&num_vtg'
    ptr_vtg = &num_vtg;

    printf("\n\n");
    printf(" ****** After ptr_vtg = &num_vtg ******\n\n");
    printf("Value of 'num_vtg'%lf\n\n", num_vtg);
    printf("Address of 'num_vtg' %p\n\n", ptr_vtg);
    printf("Value at address of 'num_vtg' =%lf\n\n", *ptr_vtg);

    return (0);
}