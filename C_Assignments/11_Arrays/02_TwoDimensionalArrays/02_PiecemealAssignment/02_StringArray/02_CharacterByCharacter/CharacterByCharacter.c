#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
    // variable declarations

    //    ***A 'STRING' IS AN ARRAY OF CHARACTERS ... so char[] IS A char ARRAY ANDA HENCE, char[] ISA 'STRING' ***
    //    ***   AN ARRAY OF char ARRAYS IS AN ARRAY OF STRINGS   !!!   ***
    //    ***   HENCE, char[] IS ONE char ARRAY AND HENCE, IS ONE STRING   ***
    //    ***   HENCE, char[][] IS AN ARRAY OF char ARRAYS AND HENCE, IS AN ARRAY OF i STRINGS   ***

    // Here, the string array can allow a maximum number of 5 strings (5 rows) and each of these 5 strings can have only upto 10 characters maximum (10 columns)

    char strArray[5][10]; // 5 ROWS (0, 1, 2, 3, 4) ->5 STRINGS (EACH STRING CANP HAVE A MAXIMUM OF 10 CHARACTERS)

    int char_size;
    int strArray_size;
    int strArray_num_elements, strArray_num_rows, strArray_num_columns;
    int i;

    // code
    printf("\n\n");

    char_size = sizeof(char);

    strArray_size = sizeof(strArray);
    printf("Size of two dimensional (2D) character array (string array) is = %d\n\n", strArray_size);

    strArray_num_rows = strArray_size / sizeof(strArray[0]);
    printf("Number of rows (strings) in two dimensional (2D) character array (string array) is = %d\n\n", strArray_num_rows);

    strArray_num_columns = sizeof(strArray[0]) / char_size;
    printf("Number of columns in two dimensional (2D) character array (string array) is = %d\n\n", strArray_num_columns);

    strArray_num_elements = strArray_num_rows * strArray_num_columns;
    printf("Maximum number of elements (characters) in two dimensional (2D) character array (string array) is = %d\n\n", strArray_num_elements);

    //   ***   PIECE-MEAL ASSIGNMENT   ***
    //   ******   ROW 1 / STRING 1   ******
    strArray[0][0] = 'M';
    strArray[0][1] = 'y';
    strArray[0][2] = '\0'; // NULL-TERMINATING CHARACTER
    //   ******   ROW 2 / STRING 2   ******
    strArray[1][0] = 'N';
    strArray[1][1] = 'a';
    strArray[1][2] = 'm';
    strArray[1][3] = 'e';
    strArray[1][4] = '\0'; // NULL-TERMINATING CHARACTER

    //   ******   ROW 3 / STRING 3   ******
    strArray[2][0] = 'i';
    strArray[2][1] = 's';
    strArray[2][2] = '\0'; // NULL-TERMINATING CHARACTER
    //   ******   ROW 4 / STRING 4   ******
    strArray[3][0] = 'V';
    strArray[3][1] = 'a';
    strArray[3][2] = 'i';
    strArray[3][3] = 'b';
    strArray[3][4] = 'h';
    strArray[3][5] = 'a';
    strArray[3][6] = 'v';
    strArray[3][7] = '\0'; // NULL-TERMINATING CHARACTER
    //   ******   ROW 5 / STRING 5   ******
    strArray[4][0] = 'G';
    strArray[4][1] = 'a';
    strArray[4][2] = 'i';
    strArray[4][3] = 'k';
    strArray[4][4] = 'w';
    strArray[4][5] = 'a';
    strArray[4][6] = 'd';
    strArray[4][7] = '\0'; // NULL-TERMINATING CHARACTER

    printf("\n\n");
    printf("The strings in the 2D character array are:\n\n");

    for (i = 0; i < strArray_num_rows; i++)
        printf("%s ", strArray[i]);

    printf("\n\n");

    return (0);
}

int MyStrlen(char str_vtg[])
{
    // variable declarations
    int j_vtg;
    int string_length_vtg = 0;

    // code
    //    *** DETERMINING EXACT LENGTH OF THE STRING, BY DETECTING THE FIRST OCCURENCE OF NULL-TERMINATING CHARACTER ( \0 ) ***
    for (j_vtg = 0; j_vtg < MAX_STRING_LENGTH; j_vtg++)
    {
        if (str_vtg[j_vtg] == '\0')
            break;
        else
            string_length_vtg++;
    }
    return (string_length_vtg);
}