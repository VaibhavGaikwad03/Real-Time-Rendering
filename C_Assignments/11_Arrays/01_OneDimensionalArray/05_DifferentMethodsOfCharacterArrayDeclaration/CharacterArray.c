#include <stdio.h>

int main(void)
{
    // variable declarations
    char chArray_01_vtg[] = {'A', 'S', 'T', 'R', 'O', 'M', 'D', 'I', 'C', 'O', 'M', 'P', '\0'}; // must give \0 explicitely for proper intialization
    char chArray_02_vtg[] = {'W', 'E', 'L', 'C', 'O', 'M', 'E', 'S', '\0'};                     // must give \0 explicitely for proper intialization
    char chArray_03_vtg[] = {'Y', 'O', 'U', '\0'};                                              // must give \0 explicitely for proper intialization
    char chArray_04_vtg[] = "To";                                                               // \0 is assumed, size is given as 3, although string has only 2 characters
    char chArray_05_vtg[] = "REAL TIME RENDERING BATCH OF 2020-21";                             // \0 is assumed, size is given as 40, although string has 39 characters

    char chArray_WithoutNullTerminator[] = {'H', 'E', 'L', 'L', 'O'};

    // code
    printf("\n\n");

    printf("Size of chArray_01_vtg: %lu\n\n", sizeof(chArray_01_vtg));
    printf("Size of chArray_02_vtg: %lu\n\n", sizeof(chArray_02_vtg));
    printf("Size of chArray_03_vtg: %lu\n\n", sizeof(chArray_03_vtg));
    printf("Size of chArray_04_vtg: %lu\n\n", sizeof(chArray_04_vtg));
    printf("Size of chArray_05_vtg: %lu\n\n", sizeof(chArray_05_vtg));

    printf("\n\n");

    printf("Strings are: \n\n");
    printf("chArray_01_vtg: %s\n\n", chArray_01_vtg);
    printf("chArray_02_vtg: %s\n\n", chArray_02_vtg);
    printf("chArray_03_vtg: %s\n\n", chArray_03_vtg);
    printf("chArray_04_vtg: %s\n\n", chArray_04_vtg);
    printf("chArray_05_vtg: %s\n\n", chArray_05_vtg);

    printf("\n\n");
    printf("Size of chArray_WithoutNullTerminator: %lu\n\n", sizeof(chArray_WithoutNullTerminator));
    printf("chArray_WithoutNullTerminator: %s\n\n", chArray_WithoutNullTerminator); // will display garbage value at the end of string due to absence of \0

    return (0);
}