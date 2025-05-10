#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
    // variable declarations
    char chArray_Original[MAX_STRING_LENGTH], chArray_Copy[MAX_STRING_LENGTH]; // A Character Array Is A String

    // code
    // *** string input ***
    printf("\n\n");
    printf("Enter a string: \n\n");
    gets_s(chArray_Original, MAX_STRING_LENGTH);

    // *** string copy ***
    strcpy(chArray_Copy, chArray_Original);

    // *** string output ***
    printf("\n\n");
    printf("The original string entered by you (i.e., 'chArray_Original[]') is: \n\n");
    printf("%s\n", chArray_Original);
    printf("\n\n");
    printf("The copied string (i.e., 'chArray_Copy[]') is: \n\n");
    printf("%s\n", chArray_Copy);

    return(0);
}