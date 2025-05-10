#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
    // variable declarations
    char chArray[MAX_STRING_LENGTH]; // characters array is a string

    // code
    printf("\n\n");
    printf("Enter a string: \n\n");
    gets_s(chArray, MAX_STRING_LENGTH);

    printf("\n\n");
    printf("String entered by you is: \n\n");
    printf("%s\n", chArray);

    return (0);
}