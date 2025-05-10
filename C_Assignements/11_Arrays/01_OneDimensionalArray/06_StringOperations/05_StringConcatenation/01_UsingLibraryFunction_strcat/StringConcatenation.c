#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
    // variable declarations
    char chArray_One[MAX_STRING_LENGTH], chArray_Two[MAX_STRING_LENGTH]; // A character array is a string

    // code
    // *** STRING INPUT ***
    printf("\n\n");
    printf("Enter first string: \n\n");
    gets_s(chArray_One, MAX_STRING_LENGTH);

    printf("\n\n");
    printf("Enter second string: \n\n");
    gets_s(chArray_Two, MAX_STRING_LENGTH);

    // *** STRING CONCAT ***
    printf("\n\n");
    printf("****** BEFORE CONCATENATION ******");
    printf("\n\n");
    printf("The original first string entered by you (i.e., 'chArray_One[]') is: \n\n");
    printf("%s\n", chArray_One);
    printf("\n\n");
    printf("The original second string entered by you (i.e., 'chArray_Two[]') is: \n\n");
    printf("%s\n", chArray_Two);

    strcat(chArray_One, chArray_Two);

    printf("\n\n");
    printf("****** AFTER CONCATENATION ******");
    printf("\n\n");
    printf("'chArray_One[]' is: \n\n");
    printf("%s\n", chArray_One);
    printf("\n\n");
    printf("'chArray_Two[]' is: \n\n");
    printf("%s\n", chArray_Two);

    return (0);
}