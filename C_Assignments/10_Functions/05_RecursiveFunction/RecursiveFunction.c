#include <stdio.h>

int main(int argc, char *argv[], char *envp[])
{
    // variable declarations
    unsigned int num_vtg;

    // function prototype
    void recursive(unsigned int);

    // code
    printf("\n\n");
    printf("Enter any number: ");
    scanf("%u", &num_vtg);

    printf("\n\n");
    printf("Output of recursive function: \n");

    recursive(num_vtg);

    printf("\n\n");

    return (0);
}

void recursive(unsigned int n)
{
    // code
    printf("n = %d\n", n);

    if (n > 0)
    {
        recursive(n - 1);
    }
}