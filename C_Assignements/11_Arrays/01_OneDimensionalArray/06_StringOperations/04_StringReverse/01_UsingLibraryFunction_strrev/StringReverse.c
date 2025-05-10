#include <stdio.h>
#include <string.h> // for strrev()

#define MAX_STRING_LENGTH 512

int main(void)
{
    // variable declarations
    char chArray_Original[MAX_STRING_LENGTH]; // A Character Array Is A String

    // code
    // *** STRING INPUT ***
    printf("\n\n");
    printf("Enter a string: \n\n");
    gets_s(chArray_Original, MAX_STRING_LENGTH);

    printf("\n\n");
    printf("The reversed string is: \n\n");
    printf("%s\n", strrev(chArray_Original));

    // *** STRING OUTPUT ***
    printf("\n\n");
    printf("The original string entered by you is: \n\n");
    printf("%s\n", chArray_Original);

    return (0);
}