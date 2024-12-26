#include <stdio.h>

int main(void) // variable declarations
{
    int num_vtg;
    int *ptr_vtg = NULL;
    int *copy_ptr_vtg = NULL;

    // code
    num_vtg = 5;
    ptr_vtg = &num_vtg;

    printf("\n\n");
    printf("****** BEFORE copy_ptr_vtg = ptr_vtg ******\n\n");
    printf("   num_vtg = %d\n", num_vtg);
    printf("   &num_vtg = %p\n", &num_vtg);
    printf("   *(&num_vtg) = %d\n", *(&num_vtg));
    printf("   ptr_vtg = %p\n", ptr_vtg);
    printf("   *ptr_vtg = %d\n", *ptr_vtg);

    //'ptr_vtg' is an integer pointer variable...that it can hold the address of any integer variable only
    //'copy_ptr_vtg' is another integer pointer variable
    // If ptr_vtg = &num_vtg ... 'ptr_vtg' will contain address of integer variable 'num_vtg'
    // If 'ptr_vtg' is assigned to 'copy_ptr_vtg', 'copy_ptr_vtg' will also contain address of integer variable 'num_vtg'
    // Hence, now, both 'ptr_vtg' and 'copy_ptr_vtg' will point to 'num_vtg' ...

    copy_ptr_vtg = ptr_vtg; // copy_ptr_vtg = ptr_vtg = &num_vtg

    printf("\n\n");
    printf("****** AFTER copy_ptr_vtg = ptr_vtg ******\n\n");
    printf("   num_vtg = %d\n", num_vtg);
    printf("   &num_vtg = %p\n", &num_vtg);
    printf("   *(&num_vtg) = %d\n", *(&num_vtg));
    printf("   ptr_vtg = %p\n", ptr_vtg);
    printf("   *ptr_vtg = %d\n", *ptr_vtg);
    printf("   copy_ptr_vtg = %p\n", copy_ptr_vtg);
    printf("   *copy_ptr_vtg = %d\n", *copy_ptr_vtg);

    return (0);
}