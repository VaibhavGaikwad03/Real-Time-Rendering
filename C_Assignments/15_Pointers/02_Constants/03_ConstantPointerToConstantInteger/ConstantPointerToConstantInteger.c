#include <stdio.h>

int main(void) // variable declarations
{
    int num_vtg = 5;
    const int *const ptr_vtg = &num_vtg; // Read this line from right to left => "ptr_vtg is a constant (const) pointer (*) to integer (int) constant (const)."

    // code
    printf("\n");
    printf("Current Value Of 'num_vtg' = % d\n", num_vtg);
    printf("Current 'ptr_vtg'(Address of 'num_vtg') = % p\n", ptr_vtg);

    // The following line does NOT give error ... as we are modifying the values of the variable individually
    num_vtg++;
    printf("\n\n");
    printf("After num_vtg++, value of 'num_vtg' = % d\n", num_vtg);

    // The following line gives error and is hence commented out.
    // We cannot alter the 'ptr_vtg' value as 'ptr_vtg' is "a constant pointer to constant integer".
    // ptr_vtg++;
    // With respect to the pointer, the value it points to is constant AND the pointer itself is also constant.
    // Uncomment it and see the error.

    // The following line also give error and is hence commented out.
    // We cannot alter the value stored in 'ptr_vtg' as 'ptr_vtg' is "A constant pointer to constant integer".
    // (*ptr_vtg)++;
    return (0);
}

// CONCLUSION :
// As "ptr_vtg" is a "constant pointer to a constant integer" - we cannot change the value stored at address "ptr_vtg" AND we cannot change the 'ptr_vtg' (Address) itself.
// We can change the value of the variable (num_vtg) individually - whose address is contained in "ptr_vtg".
// We cannot also change the "the value at address of ptr_vtg" - we cannot change the value of "num_vtg" with respect to ”ptr_vtg" => (*ptr_vtg)++ is NOT allowed.
// We cannot change the value OF 'ptr_vtg' => That is we cannot store a new address inside 'ptr_vtg' => So, ptr_vtg++ is also NOT allowed.