#include <stdio.h> // 'stdio.h' contains declaration of 'printf()'

// Entry-point function => main() => valid return type (int) and 3 parameters (int argc, char *argv[], char *envp[])

int main(int argc, char *argv[], char *envp[])
{
    // Function prototype / declaration / signature
    int MyAddition(void);

    // variable declarations : local variables to main()
    int result;

    // code
    result = MyAddition(); // function call

    printf("\n\n");
    printf("Sum = %d\n\n", result);

    return (0);
}

// ****** USER DEFINED FUNCTION : METHOD OF DEFINATION 2 ******
// ****** VALID (int) RETURN VALUE. NO PARAMETERS ******

int MyAddition(void) // function defination
{
    // variable declarations : local variable to MyAddition()
    int a, b, sum;

    // code
    printf("\n\n");
    printf("Enter integer value for 'A': ");
    scanf("%d", &a);

    printf("\n\n");
    printf("Enter integer value for 'B': ");
    scanf("%d", &b);

    sum = a + b;

    return (sum);
}