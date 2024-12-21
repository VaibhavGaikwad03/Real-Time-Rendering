#include <stdio.h>

#define MAX_STRING_LENGTH 512

// function prototype
int MyStrlen(char[]);

int main(void)
{
    // variable declarations
    char chArray[MAX_STRING_LENGTH]; // A character array is a string
    int iStringLength = 0;

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
    iStringLength = MyStrlen(chArray);
    printf("Length of string is = %d characters !! !\n\n", iStringLength);

    return(0);
}

int MyStrlen(char vtr[]) // variable declarations
{
    int j;
    int string_length = 0;

    // code
    // *** DETERMINING EXACT LENGTH OF THE STRING, BY DETECTING THE FIRST OCCURENCE OF NULL-TERMINATING CHARACTER ( \0 ) ***
    for (j = 0; j < MAX_STRING_LENGTH; j++)
    {
        if (vtr[j] != '\0')
            string_length++;
        else
            break;
    }
    return(string_length);
}