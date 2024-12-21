#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[])
{
    // variable declarations
    int i;

    // code
    if (argc != 4) // Program name + first name + middle name + surname = 4 command line arguments are required
    {
        printf("\n\n");
        printf("Invalid usage !!! Exiting now... \n\n");
        printf("Usage: CommandLineArgumentsApplication <first name> <middle name> <surname>\n\n");
        exit(0);
    }

    // *** THIS PROGRAMS PRINTS YOUR FULL NAME AS ENTERED IN THE COMMAND LINE ARGUMENTS ***

    printf("\n\n");
    printf("Your full name is: ");
    for (i = 1; i < argc; i++) // Loop starts from 1 = 1 because i = 0 will result int argv[i] = argv[0] which is the name of the program itself i.e. 'CommandLineArgumentsApplication.exe
    {
        printf("%s ", argv[i]);
    }

    printf("\n\n");

    return (0);
}