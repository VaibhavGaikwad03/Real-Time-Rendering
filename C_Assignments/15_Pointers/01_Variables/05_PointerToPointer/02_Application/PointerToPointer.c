#include <stdio.h>

int main(void)
{
    // variable declarations
    int num_vtg;
    int *ptr_vtg = NULL;
    int **pptr_vtg = NULL; // Declaration Method 1 :- **pptr_vtg IsA Variable Of type 'irt'

    // code
    num_vtg = 10;
    printf("\n\n");
    printf("****** BEFORE ptr_vtg = &num_vtg ******\n\n");
    printf("Value Of 'num_vtg' %d\r\n", num_vtg);
    printf("Address Of 'num_vtg' %p\n\n", &num_vtg);
    printf("Value At Address Of 'num_vtg' = %d\n\n", *(&num_vtg));

    // Assigning address of variable 'num_vtg' to pointer variable 'ptr_vtg'
    //'ptr_vtg' now contains address of 'num_vtg'...hence, 'ptr_vtg' is SAME as '&num_vtg'
    ptr_vtg = &num_vtg;

    printf("\n\n");
    printf("****** AFTER ptr_vtg = &num_vtg ******\n\n");
    printf("Value Of 'num_vtg' %d\n\n", num_vtg);
    printf("Address Of 'num_vtg' %p\r\n", ptr_vtg);
    printf("Value At Address Of 'num_vtg' = %d\n\n", *ptr_vtg);

    // Assigning address of variable 'ptr_vtg' to pointer-to-pointer variable
    // 'pptr_vtg' now contains the address of 'ptr_vtg' which in turn contains the address of 'num_vtg'
    // Hence, 'pptr_vtg' is SAME as '&ptr_vtg'
    // 'ptr_vtg' is SAME as '&num_vtg'
    // If ptr_vtg = &num_vtg and *ptr_vtg = *(&num_vtg) = value at address of 'num_vtg'
    // Then, pptr_vtg = &ptr_vtg and *pptr_vtg = *(&ptr_vtg) = ptr_vtg = value at address of 'ptr_vtg' i.e: 'ptr_vtg' i.e : address of 'num_vtg'
    // Then, **pptr_vtg = **(&ptr_vtg) = *(*(&ptr_vtg)) = *ptr_vtg = *(&num_vtg) = num_vtg = 10
    // Hence, num_vtg = *(&num_vtg) = *ptr_vtg = *(*pptr_vtg) = **pptr_vtg

    pptr_vtg = &ptr_vtg;

    printf("\n\n");
    printf("****** AFTER pptr_vtg = &ptr_vtg ******\n\n");
    printf("Value Of 'num_vtg' %d\n\n", num_vtg);
    printf("Address Of 'num_vtg' (ptr_vtg) %p\n\n", ptr_vtg);
    printf("Address Of 'ptr_vtg' (pptr_vtg) %p\n\n", pptr_vtg);
    printf("Value At Address Of 'ptr_vtg' (*pptr_vtg) = %p\n\n", *pptr_vtg);
    printf("Value At Address Of 'num_vtg' (*ptr_vtg) (*pptr_vtg) = %d\n\n", **pptr_vtg);

    return (0);
}