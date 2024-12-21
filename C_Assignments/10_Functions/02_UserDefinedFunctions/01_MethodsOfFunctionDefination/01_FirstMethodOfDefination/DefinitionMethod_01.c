#include <stdio.h> // 'stdio.h' contains declaration of 'printf()'

// Entry-point function => main() => valid return type (int) and 3 parameters (int argc, char *argv[], char *envp[])

int main(int argc, char *argv[], char *envp[])
{
    // Function prototype / declaration / signature
    void MyAddition(void);

    // code
    MyAddition(); // function call

    return (0);
}

// ****** USER DEFINED FUNCTION : METHOD OF DEFINATION 1 ******
// ****** NO RETURN VALUE. NO PARAMETERS ******

void MyAddition(void) // function defination
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

    printf("\n\n");
    printf("Sum of %d and %d = %d\n\n", a, b, sum);
}