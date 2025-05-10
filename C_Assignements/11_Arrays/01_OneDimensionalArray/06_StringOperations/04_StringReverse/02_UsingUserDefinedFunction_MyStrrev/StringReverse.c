#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
    // function prototype
    void MyStrrev(char str_destination[], char str_source[]);

    // variable declarations
    char chArray_Original[MAX_STRING_LENGTH], chArray_Reversed[MAX_STRING_LENGTH]; // A Character Array Is A String

    // code
    // *** string input ***
    printf("\n\n");
    printf("Please enter a string: \n\n");
    gets_s(chArray_Original, MAX_STRING_LENGTH);

    // *** string reverse ***
    MyStrrev(chArray_Reversed, chArray_Original);

    printf("\n\n");
    printf("The reversed string is: \n\n");
    printf("%s\n", chArray_Reversed);

    // *** string output ***
    printf("\n\n");
    printf("The original string you entered is: \n\n");
    printf("%s\n", chArray_Original);

    return (0);
}

// function prototype
void MyStrrev(char str_destination[], char str_source[])
{
    // function prototype
    int MyStrlen(char str[]);

    // variable declarations
    int iStringLength = 0;
    int i, j, len;

    // code
    iStringLength = MyStrlen(str_source);

    // array indices begin from 0, hence, last index will always be (length - 1)
    len = iStringLength - 1;

    // we need to put the character which is at last index of 'str_source' to the first index of 'str_destination'
    // and second-last character of 'str_source' to the second character of 'str_destination' and so on...
    for (i = 0, j = len; i < iStringLength, j >= 0; i++, j--)
    {
        str_destination[i] = str_source[j];
    }
    str_destination[i] = '\0';
}

int MyStrlen(char str[])
{
    // variable declarations
    int j;
    int string_length = 0;

    // code
    // *** determining exact length of the string, by detecting the first occurence of null-terminating character ( \0 ) ***
    for (j = 0; j < MAX_STRING_LENGTH; j++)
    {
        if (str[j] != '\0')
            string_length++;
        else
            break;
    }

    return (string_length);
}