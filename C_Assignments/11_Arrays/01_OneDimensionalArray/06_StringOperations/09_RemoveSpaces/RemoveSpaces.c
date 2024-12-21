#include <stdio.h>

#define max_string_length 512

int main(void)
{
    // function prototype
    int my_strlen(char[]);
    void my_strcpy(char[], char[]);

    // variable declarations
    char char_array[max_string_length], char_array_spaces_removed[max_string_length]; // a character array is a string
    int i_string_length;
    int i, j;

    // code
    //  *** STRING INPUT ***
    printf("\n\n");
    printf("Enter a string : \n\n");
    gets_s(char_array, max_string_length);

    i_string_length = my_strlen(char_array);
    j = 0;
    for (i = 0; i < i_string_length; i++)
    {
        if (char_array[i] == ' ')
            continue;
        else
        {
            char_array_spaces_removed[j] = char_array[i];
            j++;
        }
    }
    char_array_spaces_removed[j] = '\0';

    // *** STRING OUTPUT ***
    printf("\n\n");
    printf("String entered by you is : \n\n");
    printf("%s\n", char_array);
    printf("\n\n");
    printf("String after removal of spaces is : \n\n");
    printf("%s\n", char_array_spaces_removed);

    return (0);
}

int my_strlen(char str[])
{
    // variable declarations
    int j;
    int string_length = 0;

    // code
    //  *** DETERMINING EXACT LENGTH OF THE STRING, BY DETECTING THE FIRST OCCURRENCE OF NULL-TERMINATING CHARACTER ( \0 ) ***
    for (j = 0; j < max_string_length; j++)
    {
        if (str[j] != '\0')
            string_length++;
        else
            break;
    }

    return (string_length);
}