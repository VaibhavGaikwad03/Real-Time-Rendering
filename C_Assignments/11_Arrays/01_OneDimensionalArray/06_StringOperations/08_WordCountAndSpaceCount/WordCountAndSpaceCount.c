#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
    // function prototype
    int MyStrlen(char vtr[]);
    void MyStrcpy(char vtr1[], char vtr2[]);

    // variable declarations
    char chArray[MAX_STRING_LENGTH]; // A character array is a string
    int iStringLength;
    int i;
    int word_count = 0, space_count = 0;

    // code
    //  *** STRING INPUT ***
    printf("\n\n");
    printf("Enter a string: \n\n");
    gets_s(chArray, MAX_STRING_LENGTH);

    iStringLength = MyStrlen(chArray);

    for (i = 0; i < iStringLength; i++)
    {
        switch (chArray[i])
        {
        case 32: // 32 IS THE ASCII VALUE FOR SPACE (' ') CHARACTER
            space_count++;
            break;
        default:
            break;
        }
    }
    word_count = space_count + 1;

    // *** STRING OUTPUT ***
    printf("\n\n");
    printf("The string you entered is: \n\n");
    printf("%s\n", chArray);
    printf("\n\n");
    printf("The number of spaces in the input string is %d.\n\n", space_count);
    printf("The number of words in the input string is %d.\n\n", word_count);

    return (0);
}

int MyStrlen(char vtr[])
{
    // variable declarations
    int j;
    int string_length = 0;

    // code
    //  *** DETERMINING EXACT LENGTH OF THE STRING, BY DETECTING THE FIRST OCCURENCE OF NULL-TERMINATING CHARACTER ( \0 ) ***
    for (j = 0; j < MAX_STRING_LENGTH; j++)
    {
        if (vtr[j] != '\0')
        {
            string_length++;
        }
        else
        {
            break;
        }
    }

    return (string_length);
}