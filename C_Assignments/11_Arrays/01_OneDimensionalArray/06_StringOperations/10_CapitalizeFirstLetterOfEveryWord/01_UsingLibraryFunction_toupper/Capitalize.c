#include <stdio.h>
#include <ctype.h> // for toupper()

#define MAX_STRING_LENGTH 512

int main(void)
{
    // function prototype
    int MyStrlen(char[]);

    // variable declarations
    char chArray[MAX_STRING_LENGTH], chArray_CapitalizedFirstLetterOfEveryWord[MAX_STRING_LENGTH]; // A character array is string
    int iStringLength;
    int i, j;

    // code
    // *** STRING INPUT ***
    printf("\n\n");
    printf("Enter a string : \n\n");
    gets_s(chArray, MAX_STRING_LENGTH);

    iStringLength = MyStrlen(chArray);
    j = 0;
    for (i = 0; i < iStringLength; i++)
    {
        if (i == 0)
            chArray_CapitalizedFirstLetterOfEveryWord[j] = toupper(chArray[i]);
        else if (chArray[i] == ' ')
        {
            chArray_CapitalizedFirstLetterOfEveryWord[j] = chArray[i];
            chArray_CapitalizedFirstLetterOfEveryWord[j + 1] = toupper(chArray[i + 1]); // SINCE, ALREADY TWO CHARACTERS (AT INDICES 'i' AND i + 1 HAVE BEEN CONSIDERED IN THIS else-if BLOCK...WE ARE EXTRA-INCREMENTING 'i' AND 'j' BY 1
            j++;
            i++;
        }
        else
            chArray_CapitalizedFirstLetterOfEveryWord[j] = chArray[i];
        j++;
    }
    chArray_CapitalizedFirstLetterOfEveryWord[j] = '\0';

    // *** STRING OUTPUT ***
    printf("\n\n");
    printf("String entered by you is : \n\n");
    printf("%s\n", chArray);

    printf("\n\n");
    printf("String after capitalizing first letter of every word: \n\n");
    printf("%s\n", chArray_CapitalizedFirstLetterOfEveryWord);

    return (0);
}

int MyStrlen(char str[]) // variable declarations
{
    int j;
    int string_length = 0;

    // code
    // *** DETERMINING EXACT LENGTH OF THE STRING, BY DETECTING THE FIRST OCCURENCE OF NULL-TERMINATING CHARACTER ( \0 ) ***
    for (j = 0; j < MAX_STRING_LENGTH; j++)
    {
        if (str[j] == '\0')
            break;
        else
            string_length++;
    }
    return (string_length);
}