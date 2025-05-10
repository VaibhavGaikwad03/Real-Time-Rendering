#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
    // variable declarations
    char chArray[MAX_STRING_LENGTH];
    int is_string_length = 0;

    // code

    // *** STRING INPUT ***
    printf("\n\n");
    printf("Enter a string: \n\n");
    gets_s(chArray, MAX_STRING_LENGTH);

    // *** STRING OUTPUT ***
    printf("\n\n");
    printf("String entered by you is: \n\n");
    printf("%s\n", chArray);

    // *** STRING LENGTH ***
    printf("\n\n");
    is_string_length = strlen(chArray);
    printf("Length of string is = %d characters!!!\n\n", is_string_length);

    return (0);
}