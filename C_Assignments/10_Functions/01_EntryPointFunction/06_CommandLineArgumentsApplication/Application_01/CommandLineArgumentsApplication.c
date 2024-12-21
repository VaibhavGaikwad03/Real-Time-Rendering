#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[])
{
    // variable declarations
    int i;
    int num;
    int sum = 0;

    // code
    if (argc == 1)
    {
        printf("\n\n");
        printf("No numbers given for addition!!! Exiting now... \n\n");
        printf("Usage: COmmandLineArgumentApplication <first number> <second number>... \n\n");
        exit(0);
    }

    // *** THIS PROGRAMS ADDS ALL COMMAND LINE ARGUMENTS GIVEN IN INTEGER FROM ONLY AND OUTPUTS THE SUM ***
    // *** DUE TO USE OF atoi(), ALL COMMAND LINE ARGUMENTS OF TYPES OTHER THAT 'int' AREIGNORED ***

    printf("\n\n");
    printf("Sum of all integer command line arguments is: \n\n");
    for (i = 1; i < argc; i++) // Loop starts from 1 = 1 because i = 0 will result int argv[i] = argv[0] which is the name of the program itself i.e. 'CommandLineArgumentsApplication.exe
    {
        num = atoi(argv[i]);
        sum = sum + num;
    }

    printf("Sum = %d\n\n", sum);

    return (0);
}