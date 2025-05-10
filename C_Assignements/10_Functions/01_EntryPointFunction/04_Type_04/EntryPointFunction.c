#include <stdio.h> // stdio.h contains declarations of 'printf()'

// Entry-point function => main() => valid return type (int) and 2 parameters (int argc, char *argv[])

int main(int argc, char *argv[])
{
    // variable declarations
    int i;

    // code
    printf("\n\n");
    printf("Hello, World!!!\n"); // Library function
    printf("Number of command line arguments = %d\n\n", argc);

    printf("Command line arguments passed to this program are: \n\n");
    for (i = 0; i < argc; i++)
    {
        printf("Command line argument number %d = %s\n", (i + 1), argv[i]);
    }

    printf("\n\n");

    return (0);
}