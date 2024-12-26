#include <stdio.h>

int main(void)
{
    int num_vtg = 5;           // variable declarations
    const int *ptr_vtg = NULL; // Read this line from right to left => "ptr is a pointer (*) to integer (int) constant (const)."

    // code
    ptr_vtg = &num_vtg;
    printf("\n");
    printf("Current Value Of 'num' = %d\n", num_vtg);
    printf("Current 'ptr' (Address of 'num') = %p\n", ptr_vtg);

    // The following line does NOT give error ... as we are modifying the value of the variable individually
    num_vtg++;
    printf("\n\n");
    printf("After num++, value of 'num' = %d\n", num_vtg);

    // The following line gives error and is hence commented out.
    // We cannot alter the value stored in "A pointer to constant integer"
    // With respect to the pointer, the value it points to should be constant.
    // Uncomment it and see the error.
    // (*ptr_vtg)++;

    // The following line does NOT give error
    // We do not get error because we are changing the pointer (address).
    // The pointer is not constant. The value to which the pointer points is constant.
    ptr_vtg++;

    printf("\n\n");
    printf("After ptr++, value of 'ptr' = %p\n", ptr_vtg);
    printf("Value at this new 'ptr' = %d\n", *ptr_vtg);
    printf("\n");

    return (0);

    // CONCLUSION :
    // As "ptr" is a "variable pointer to constant integer" - we can change the value of pointer "ptr".
    // We can change the value of the variable (num) individually - whose address is contained in "ptr".
    // So in short, we cannot change "the value at address of ptr" - we cannot change the value of "num" with respect to "ptr" => (*ptr)++ is NOT allowed.
    // But, we can change the address 'ptr' itself => So, ptr++ is allowed.
}