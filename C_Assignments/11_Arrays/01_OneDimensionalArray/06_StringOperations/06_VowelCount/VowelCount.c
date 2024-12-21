#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
    // function prototype
    int MyStrlen(char[]);

    // variable declarations
    char chArray[MAX_STRING_LENGTH]; // A character array is string
    int iStringLength;
    int count_A = 0, count_E = 0, count_I = 0, count_O = 0, count_U = 0; // Initial Counts =0
    int i;

    // code
    //  *** STRING INPUT ***
    printf("\n\n");
    printf("Enter a string: \n\n");
    gets_s(chArray, MAX_STRING_LENGTH);

    // *** STRING OUTPUT ***
    printf("\n\n");
    printf("The string you entered is: \n\n");
    printf("%s\n", chArray);

    iStringLength = MyStrlen(chArray);

    for (i = 0; i < iStringLength; i++)
    {
        switch (chArray[i])
        {
        case 'A':
        case 'a':
            count_A++;
            break;
        case 'E':
        case 'e':
            count_E++;
            break;
        case 'I':
        case 'i':
            count_I++;
            break;
        case 'O':
        case 'o':
            count_O++;
            break;
        case 'U':
        case 'u':
            count_U++;
            break;
        default:
            break;
        }
    }

    printf("\n\n");
    printf("The vowels and their occurrences in the string you entered are as follows: \n\n");
    printf("The letter 'A' has occurred %d times.\n\n", count_A);
    printf("The letter 'E' has occurred %d times.\n\n", count_E);
    printf("The letter 'I' has occurred %d times.\n\n", count_I);
    printf("The letter 'O' has occurred %d times.\n\n", count_O);
    printf("The letter 'U' has occurred %d times.\n\n", count_U);

    return (0);
}

int MyStrlen(char str[])
{
    // variable declarations
    int j;
    int string_length = 0;

    // code
    //  *** DETERMINING EXACT LENGTH OF THE STRING, BY DETECTING THE FIRST OCCURENCE OF NULL-TERMINATING CHARACTER ( \0 ) ***
    for (j = 0; j < MAX_STRING_LENGTH; j++)
    {
        if (str[j] != '\0')
            string_length++;
        else
            break;
    }
    return (string_length);
}