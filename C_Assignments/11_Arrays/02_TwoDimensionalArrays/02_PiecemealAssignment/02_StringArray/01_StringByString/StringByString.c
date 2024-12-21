#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
    // function prototype
    void MyStrcpy(char[], char[]);

    // variable declarations

    //    ***A 'STRING' IS AN ARRAY OF CHARACTERS ... so char[] IS A char ARRAY AND HENCE, char[] ISA 'STRING' ***
    //    *** AN ARRAY OF char ARRAYS IS AN ARRAY OF STRINGS !!! ***
    //    *** HENCE, char[] IS ONE char ARRAY AND HENCE, IS ONE STRING ***
    //    *** HENCE, char[][ ] IS AN ARRAY OF char ARRAYS AND HENCE, IS AN ARRAY OF STRINGS ***
    // Here, the string array can allow a maximum number of 5 strings (5 rows) and each of these 5 strings can have only upto 10 characters maximum (10 columns)

    char strArray_vtg[5][10]; // 5 ROWS (0, 1, 2, 3, 4) -> 5 STRINGS (EACH STRING CAN HAVE A MAXIMUM OF 10 CHARACTERS)

    int char_size_vtg;
    int strArray_size_vtg;
    int strArray_num_elements_vtg, strArray_num_rows_vtg, strArray_num_columns_vtg;
    int i_vtg;

    // code
    printf("\n\n");

    char_size_vtg = sizeof(char);

    strArray_size_vtg = sizeof(strArray_vtg);
    printf("Size of two dimensional (2D) character array (string array) is = %d  \n\n", strArray_size_vtg);

    strArray_num_rows_vtg = strArray_size_vtg / sizeof(strArray_vtg[0]);
    printf("Number of rows (strings) in two dimensional (2D) character array (string array) is = %d\n\n", strArray_num_rows_vtg);

    strArray_num_columns_vtg = sizeof(strArray_vtg[0]) / char_size_vtg;
    printf("Number of columns in two dimensional (2D) character array (string array) is = %d\n\n", strArray_num_columns_vtg);

    strArray_num_elements_vtg = strArray_num_rows_vtg * strArray_num_columns_vtg;
    printf("Maximum number of elements (characters) in two dimensional (2D) character array (string array) is = %d\n\n", strArray_num_elements_vtg);

    //   *** PIECE-MEAL ASSIGNMENT ***
    MyStrcpy(strArray_vtg[0], "My");
    MyStrcpy(strArray_vtg[1], "Name");
    MyStrcpy(strArray_vtg[2], "Is");
    MyStrcpy(strArray_vtg[3], "Vaibhav");
    MyStrcpy(strArray_vtg[4], "Gaikwad");

    printf("\n\n");
    printf("The strings in the 2D character array are:   \n\n");

    for (i_vtg = 0; i_vtg < strArray_num_rows_vtg; i_vtg++)
        printf("%s ", strArray_vtg[i_vtg]);

    printf("\n\n");

    return (0);
}

void MyStrcpy(char str_destination_vtg[], char str_source_vtg[])
{
    // function prototype
    int MyStrlen(char[]);

    // variable declarations
    int iStringLength_vtg = 0;
    int j_vtg;

    // code
    iStringLength_vtg = MyStrlen(str_source_vtg);
    for (j_vtg = 0; j_vtg < iStringLength_vtg; j_vtg++)
        str_destination_vtg[j_vtg] = str_source_vtg[j_vtg];
    str_destination_vtg[j_vtg] = '\0';
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