// *** GLOBAL SCOPE ***
// global_count is a variable declared in source code file ExternGlobalVariablesInMultipleFiles.c
// To access it in this file, it must first be re-declared as an external variable in the global scope of this file along with the 'extern' keyword and its proper data type
// Then, it can be used as any ordinary global variable throughout this file as well

#include <stdio.h>

extern int global_count_vtg;

void change_count_one(void)
{
    // code
    global_count_vtg = global_count_vtg + 1;
    printf("change_count_one(): Value of global_count in File_01 = %d\n", global_count_vtg);
}