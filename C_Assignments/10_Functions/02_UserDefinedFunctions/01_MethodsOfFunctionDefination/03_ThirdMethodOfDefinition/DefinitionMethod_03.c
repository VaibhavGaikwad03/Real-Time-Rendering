#include <stdio.h> // 'stdio.h' contains declaration of 'printf()'

// Entry-point function => main() => valid return type (int) and 3 parameters (int argc, char *argv[], char *envp[])

int main(int argc, char *argv[], char *envp[])
{
    // Function prototype / declaration / signature
    void MyAddition(int, int);

    // variable declarations : local variables to main()
    int a, b;

    // code
    printf("\n\n");
    printf("Enter integer value for 'A': ");
    scanf("%d", &a);

    printf("\n\n");
    printf("Enter integer value for 'B': ");
    scanf("%d", &b);

    MyAddition(a, b); // function call

    return (0);
}

// ****** USER DEFINED FUNCTION : METHOD OF DEFINATION 2 ******
// ****** NO RETURN VALUE. VALID PARAMETERS (int, int) ******

void MyAddition(int a, int b) // function defination
{
    // variable declarations : local variable to MyAddition()
    int sum;

    // code
    sum = a + b;
    printf("\n\n");
    printf("Sum of %d and %d = %d\n\n", a, b, sum);
}