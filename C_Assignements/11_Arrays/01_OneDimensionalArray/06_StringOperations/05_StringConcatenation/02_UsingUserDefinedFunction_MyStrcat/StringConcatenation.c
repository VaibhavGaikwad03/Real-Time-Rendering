#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
    // function prototype
    void MyStrcat(char str_destination[], char str_source[]);

    // variable declarations
    char chArray_One[MAX_STRING_LENGTH], chArray_Two[MAX_STRING_LENGTH]; // A Character Array Is A String

    // code
    // *** string input ***
    printf("\n\n");
    printf("Enter the first string: \n\n");
    gets_s(chArray_One, MAX_STRING_LENGTH);
    printf("\n\n");
    printf("Enter the second string: \n\n");
    gets_s(chArray_Two, MAX_STRING_LENGTH);

    // *** string concat ***
    printf("\n\n");
    printf("Before concatenation: \n\n");
    printf("The original first string you entered is: \n\n");
    printf("%s\n", chArray_One);
    printf("\n\n");
    printf("The original second string you entered is: \n\n");
    printf("%s\n", chArray_Two);

    MyStrcat(chArray_One, chArray_Two);
    printf("\n\n");
    printf("After concatenation: \n\n");
    printf("The first string is now: \n\n");
    printf("%s\n", chArray_One);
    printf("\n\n");
    printf("The second string remains the same: \n\n");
    printf("%s\n", chArray_Two);

    return (0);
}

void MyStrcat(char str_destination[], char str_source[])
{
    // function prototype
    int MyStrlen(char str[]);

    // variable declarations
    int iStringLength_Source = 0, iStringLength_Destination = 0;
    int i, j;

    // code
    iStringLength_Source = MyStrlen(str_source);
    iStringLength_Destination = MyStrlen(str_destination);

    // array indices begin from 0, hence, last valid index of array will always be (length - 1)
    // so, concatenation must begin from index number equal to length of the array 'str_destination'
    // we need to put the character which is at first index of 'str_source' to the i (last index + 1) of 'str_destination'
    for (i = iStringLength_Destination, j = 0; j < iStringLength_Source; i++, j++)
        str_destination[i] = str_source[j];
    str_destination[i] = '\0';
}

int MyStrlen(char str[])
{
    // variable declarations
    int j;
    int string_length = 0;

    // code
    // *** determining exact length of the string, by detecting the first occurrence of null-terminating character ( \0 ) ***
    for (j = 0; j < MAX_STRING_LENGTH; j++)
    {
        if (str[j] != '\0')
            string_length++;
        else
            break;
    }
    return (string_length);
}