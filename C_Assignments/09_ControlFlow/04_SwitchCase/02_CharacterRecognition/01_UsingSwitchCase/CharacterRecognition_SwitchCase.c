#include <stdio.h>
#include <conio.h>

// ASCII values for 'A' to 'Z' => 65 to 90
#define CHAR_ALPHABET_UPPER_CASE_BEGINNING 65
#define CHAR_ALPHABET_UPPER_CASE_ENDING 90

// ASCII values for 'a' to 'z' => 97 to 122
#define CHAR_ALPHABET_LOWER_CASE_BEGNNING 97
#define CHAR_ALPHABET_LOWER_CASE_ENDING 122

// ASCII values for '0' to '9' => 48 to 57
#define CHAR_DIGIT_BEGINNING 48
#define CHAR_DIGIT_ENDING 57

int main(void)
{
    // variable declarations
    char ch;
    int ch_value;

    // code
    printf("\n\n");

    printf("Enter character: ");
    ch = getch();

    printf("\n\n");

    switch (ch)
    {
    // FALL THROUGH CONDITION...
    case 'A':
    case 'a':

    case 'E':
    case 'e':

    case 'I':
    case 'i':

    case 'O':
    case 'o':

    case 'U':
    case 'u':
        printf("Character \'%c\'entered by you, is a VOWEL CHARACTER from the english alphabet!!!\n\n", ch);
        break;

    default:
        ch_value = (int)ch;
        // If the character has ASCII value between 65 AND 90 OR between 97 AND 122, it is still a letter of the alphabet, but it is a 'CONSONANT', and NOT a 'VOWEL'...
        if ((ch_value >= CHAR_ALPHABET_UPPER_CASE_BEGINNING && ch_value <= CHAR_ALPHABET_UPPER_CASE_ENDING) || (ch_value >= CHAR_ALPHABET_LOWER_CASE_BEGNNING && ch_value <= CHAR_ALPHABET_LOWER_CASE_ENDING))
        {
            printf("Character \'%c\' entered by you, is a CONSONANT CHARACTER from the english alphabet!!!\n\n", ch);
        }
        else if (ch_value >= CHAR_DIGIT_BEGINNING && ch_value <= CHAR_DIGIT_ENDING)
        {
            printf("Character \'%c\' entered by you, is a DIGIT CHARACTER!!!\n\n", ch);
        }
        else
        {
            printf("Character \'%c\' entered by you, is a SPECIAL CHARACTER!!!\n\n", ch);
        }
        break;
    }

    printf("Switch case block complete!!!\n");

    return (0);
}