#include <stdio.h>

int main(void)
{
    // variable declarations
    int num_vtg = 5;
    int *const ptr_vtg = &num_vtg; // Read this line from right to left => "ptr_vtg is a constant (const) pointer (*) to integer (int)."

    // code
    printf("\n");
    printf("Current Value Of 'num_vtg' = %d\n", num_vtg);
    printf("Current 'ptr_vtg' (Address of 'num_vtg') = %p\n", ptr_vtg);

    // The following line does NOT give error ... as we are modifying the values of the variable individually
    num_vtg++;
    printf("\n\n");
    printf("After num_vtg++, value of 'num_vtg' = %d\n", num_vtg);

    // The following line gives error and is hence commented out.
    // We cannot alter the 'ptr_vtg' value as 'ptr_vtg' is "a constant pointer to
    // ptr_vtg++;

    // The following line does NOT give error
    // We do not get error because we are changing the value at a constant integer".
    // With respect to the pointer, the value it points to is not constant but the pointer itself is constant.
    // Uncomment it and see the error.
    // pointer (address).
    // The pointer is constant. The value to which the pointer points is NOT constant.
    (*ptr_vtg)++;

    printf("\n\n");
    printf("After (*ptr_vtg)++, value of 'ptr_vtg' = %p\n", ptr_vtg);
    printf("Value at this 'ptr_vtg' = %d\n", *ptr_vtg);
    printf("\n");

    return (0);

    // CONCLUSION :
    // As "ptr_vtg" is a "constant pointer to a variable integer" - we can change the
    // value stored at address "ptr_vtg" but we cannot change the 'ptr_vtg' (Address) itself.
    // We can change the value of the variable (num_vtg) individually - whose address
    // is contained in "ptr_vtg".
    // We can also change the "the value at address of ptr_vtg" - we can change the
    // value of "num_vtg" with respect to "ptr_vtg" => (*ptr_vtg)++ is allowed
    // We cannot change the value OF 'ptr_vtg' => That is we cannot store a new address
    // inside 'ptr_vtg' => So, ptr_vtg++ is NOT allowed
}