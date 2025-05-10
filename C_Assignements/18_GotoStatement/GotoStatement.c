#include <stdio.h>
#include <string.h> // for toupper()

int main(void)
{
    // variable declarations
    char ch_vtg, ch_i_vtg;
    unsigned int ascii_ch_vtg = 0;

    // code
    printf("\n\n");
    printf("Enter the first character of first name: ");
    ch_vtg = getch();

    ch_vtg = toupper(ch_vtg);

    for (ch_i_vtg = 'A'; ch_i_vtg <= 'Z'; ch_i_vtg++)
    {
        if (ch_vtg == ch_i_vtg)
        {
            ascii_ch_vtg = (unsigned int)ch_vtg;
            goto result_output; // program flow jumps directly to label ”result_output"
        }
    }

    printf("\n\n");
    printf("Goto statement not executed, so printing \"Hello, world !!!\".  \n"); // will be omitted if 'goto' statement is executed

result_output: // Label itself does not alter flow of program. Following code is executed regardless of whether goto statement is executed or not.
    printf("\n\n");

    if (ascii_ch_vtg == 0)
    {
        printf("You must have a strange name! Could not find the character '%c' in the entire English alphabet!\n", ch_vtg);
    }
    else
    {
        printf("Character '%c' found. It has ASCII value %u.\n", ch_vtg, ascii_ch_vtg);
    }

    printf("\n\n");
    
    return (0);
}