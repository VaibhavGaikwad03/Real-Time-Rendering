#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_STRING_LENGTH 1024

struct CharacterCount
{
    char ch_vtg;
    int ch_count_vtg;
} character_and_count_vtg[] = {
    {'A', 0}, // character_and_count_vtg[0].ch_vtg   =   'A'   &   character_and_count_vtg[0].ch_count_vtg   =0
    {'B', 0}, // character_and_count_vtg[1].ch_vtg   =   'B'   &   character_and_count_vtg[1].ch_count_vtg   =0
    {'C', 0}, // character_and_count_vtg[2].ch_vtg   =   'C'   &   character_and_count_vtg[2].ch_count_vtg   =0
    {'D', 0}, // character_and_count_vtg[3].ch_vtg   =   'D'   &   character_and_count_vtg[3].ch_count_vtg   =0
    {'E', 0}, // character_and_count_vtg[4].ch_vtg   =   'E'   &   character_and_count_vtg[4].ch_count_vtg   =0
    {'F', 0},
    {'G', 0},
    {'H', 0},
    {'I', 0},
    {'J', 0},
    {'K', 0},
    {'L', 0},
    {'M', 0},
    {'N', 0},
    {'O', 0},
    {'P', 0},
    {'Q', 0},
    {'R', 0},
    {'S', 0},
    {'T', 0},
    {'U', 0},
    {'V', 0},
    {'W', 0},
    {'X', 0},
    {'Y', 0},
    {'Z', 0} // character_and_count_vtg[25].ch_vtg   =   'Z'   &   character_and_count_vtg[25].ch_count_vtg   =0
};

#define SIZE_OF_ENTIRE_ARRAY_OF_STRUCTS sizeof(character_and_count_vtg)
#define SIZE_OF_ONE_STRUCT_FROM_THE_ARRAY_OF_STRUCTS sizeof(character_and_count_vtg[0])
#define NUM_ELEMENTS_IN_ARRAY (SIZE_OF_ENTIRE_ARRAY_OF_STRUCTS / SIZE_OF_ONE_STRUCT_FROM_THE_ARRAY_OF_STRUCTS)

// ENTRY POINT FUNCTION
int main(void)
{
    // variable declarations
    char str_vtg[MAX_STRING_LENGTH];
    int i_vtg, j_vtg, actual_string_length_vtg = 0;

    // code
    printf("\n\n");
    printf("Enter a string: \n\n");
    gets_s(str_vtg, MAX_STRING_LENGTH);

    actual_string_length_vtg = strlen(str_vtg);
    printf("\n\n");
    printf("The string you have entered is: \n\n");
    printf("%s\n\n", str_vtg);

    for (i_vtg = 0; i_vtg < actual_string_length_vtg; i_vtg++)
    {
        for (j_vtg = 0; j_vtg < NUM_ELEMENTS_IN_ARRAY; j_vtg++) // Run every character of the input string through the entire alphabet (A TO Z)
        {
            str_vtg[i_vtg] = toupper(str_vtg[i_vtg]);                    // If input character is in lower case, turn it to upper case for comparison
            if (str_vtg[i_vtg] == character_and_count_vtg[j_vtg].ch_vtg) // If character is present...
                character_and_count_vtg[j_vtg].ch_count_vtg++;           // Increment its count by 1
        }
    }

    printf("\n\n");
    printf("The number of occurrences of all characters from the alphabet are as follows: \n\n");
    for (i_vtg = 0; i_vtg < NUM_ELEMENTS_IN_ARRAY; i_vtg++)
    {
        printf("Character %c %d\n", character_and_count_vtg[i_vtg].ch_vtg, character_and_count_vtg[i_vtg].ch_count_vtg);
    }

    printf("\n\n");

    return (0);
}