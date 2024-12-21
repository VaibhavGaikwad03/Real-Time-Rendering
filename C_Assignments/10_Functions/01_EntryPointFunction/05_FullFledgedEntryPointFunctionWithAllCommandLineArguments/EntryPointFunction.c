#include <stdio.h> // stdio.h contains declarations of 'printf()'

// Entry-point function => main() => valid return type (int) and 3 parameters (int argc, char *argv[], char *envp[])

int main(int argc, char *argv[], char *envp[])
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

    printf("First 20 environmental variables passed to this program are: \n\n");
    for (i = 0; i < 20; i++)
    {
        printf("Environmental variable number %d = %s\n", (i + 1), envp[i]);
    }

    printf("\n\n");

    return (0);
}