#include <stdio.h>

// DEFINING STRUCT
struct MyData
{
    int i_vtg;
    float f_vtg;
    double d_vtg;
    char c_vtg;
};

main(void)
{
    // variable declarations
    //  35 will be assigned to 'i_vtg' of 'data_one_vtg'
    //  3.9 will be assigned to 'f_vtg' of 'data_one_vtg'
    //  1.23765 will be assigned to 'd_vtg' of 'data_one_vtg'
    //  'A' will be assigned to 'c_vtg' of 'data_one_vtg'
    struct MyData data_one_vtg = {35, 3.9f, 1.23765, 'A'}; // Inline Initialization

    // 'P' will be assigned to 'i_vtg' of 'data_two_vtg' ... but 'P' is a character (char)+ and 'i_vtg' is an integer ... so 'P' is converted into it decimal integer ASCIIS value (80) and 80 is assigned to 'i_vtg' of data_two_vtg
    // 6.2 will be assigned to 'f_vtg' of 'data_two_vtg'
    // 12.199523 will be assigned to 'd_vtg' of 'data_two_vtg'
    // 68 will be assigned to 'c_vtg' of 'data_two_vtg' ... but 68 is an integer (int) and 'c_vtg' is a 'char' ... so 68 is considered as a decimal ASCII value and its corresponding character ('D') is assigned to 'c_vtg' of data_two_vtg
    struct MyData data_two_vtg = {'P', 6.2f, 12.199523, 68}; // Inline Initialization

    // 36 will be assigned to 'i_vtg' of 'data_three_vtg'
    // 'G' is 'char', but 'f_vtg' of 'data_three_vtg' is 'float'...hence, ’G' is converted to its decimal integer ASCII value (71) and this in turn is converted to 'float' (71.000000) and then it will be assigned to 'f_vtg' of 'data_three_vtg'
    // 0.0000000 will be assigned to 'd_vtg' of 'data_three_vtg'
    // No character will be assigned to 'c_vtg' of 'data_three_vtg'
    struct MyData data_three_vtg = {36, 'G'}; // Inline Initialization

    // 79 will be assigned to 'i_vtg' of 'data_four_vtg'
    // 0.000000 will be assigned to 'f_vtg' of 'data_four_vtg'
    // 0.000000 will be assigned to 'd_vtg' of 'data_four_vtg'
    // No character will be assigned to 'c_vtg' of 'data_four_vtg'
    struct MyData data_four_vtg = {79}; // Inline Initialization

    // Displaying Values Of The Data Members Of 'struct MyData'
    printf("\n\n");
    printf("DATA MEMBERS OF 'struct MyData data_one_vtg' ARE : \n\n");
    printf("i = %d\n", data_one_vtg.i_vtg);
    printf("f = %f\n", data_one_vtg.f_vtg);
    printf("d = %lf\n", data_one_vtg.d_vtg);
    printf("c = %c\n", data_one_vtg.c_vtg);

    printf("\n\n");
    printf("DATA MEMBERS OF 'struct MyData data_two_vtg' ARE : \n\n");
    printf("i = %d\n", data_two_vtg.i_vtg);
    printf("f = %f\n", data_two_vtg.f_vtg);
    printf("d = %lf\n", data_two_vtg.d_vtg);
    printf("c = %c\n", data_two_vtg.c_vtg);

    printf("\n\n");
    printf("DATA MEMBERS OF 'struct MyData data_three_vtg' ARE : \n\n");
    printf("i = %d\n", data_three_vtg.i_vtg);
    printf("f = %f\n", data_three_vtg.f_vtg);
    printf("d = %lf\n", data_three_vtg.d_vtg);
    printf("c = %c\n", data_three_vtg.c_vtg);

    printf("\n\n");
    printf("DATA MEMBERS OF 'struct MyData data_four_vtg' ARE : \n\n");
    printf("i = %d\n", data_four_vtg.i_vtg);
    printf("f = %f\n", data_four_vtg.f_vtg);
    printf("d = %lf\n", data_four_vtg.d_vtg);
    printf("c = %c\n", data_four_vtg.c_vtg);

    return (0);
}