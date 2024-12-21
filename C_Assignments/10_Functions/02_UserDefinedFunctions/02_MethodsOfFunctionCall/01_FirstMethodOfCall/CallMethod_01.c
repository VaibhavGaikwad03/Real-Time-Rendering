#include <stdio.h> //'stdio.h' contains declaration of 'printf()"

// ****** USER DEFINED FUNCTIONS : METHOD OF CALLING FUNCTION 1 ******
// ****** CALLING ALL FUNCTIONS IN main() DIRECTLYF ******

int main(int argc, char *argv[], char *envp[])
{
    // function prototypes OR declarations
    void MyAddition(void);
    int MySubtraction(void);
    void MyMultiplication(int, int);
    int MyDivision(int, int);

    // variable declarations
    int result_subtraction;
    int a_multiplication, b_multiplication;
    int a_division, b_division, result_division;

    // code

    //  *** ADDITION ***
    MyAddition(); // function call

    // *** SUBTRACTION ***
    result_subtraction = MySubtraction(); // function call
    printf("\n\n");
    printf("Subtraction yields result = %d\n", result_subtraction);

    // *** MULTIPLICATION ***
    printf("\n\n");
    printf("Enter integer value for 'A' for multiplication : ");
    scanf("%d", &a_multiplication);

    printf("\n\n");
    printf("Enter integer value for 'B' for multiplication : ");
    scanf("%d", &b_multiplication);
    MyMultiplication(a_multiplication, b_multiplication); // function call

    // *** DIVISION ***
    printf("\n\n");
    printf("Enter integer value for 'A' for division : ");
    scanf("%d", &a_division);

    printf("\n\n");
    printf("Enter integer value for 'B' for division : ");
    scanf("%d", &b_division);
    result_division = MyDivision(a_division, b_division); // function call

    printf("\n\n");
    printf("Division of %d and %d gives = %d (Quotient)\n", a_division, b_division, result_division);

    printf("\n\n");
    return (0);
}

// *** Function definition of MyAddition() ***
void MyAddition(void) // function definition
{
    // variable declarations : local variables to MyAddition()
    int a, b, sum;

    // code
    printf("\n\n");
    printf("Enter integer value for 'A' for addition : ");
    scanf("%d", &a);

    printf("\n\n");
    printf("Enter integer value for 'B' For addition : ");
    scanf("%d", &b);

    sum = a + b;

    printf("\n\n");
    printf("Sum of %d and %d = %d\n\n", a, b, sum);
}

// *** Function definition of MySubtraction() ***
int MySubtraction(void) // function definition
{
    // variable declarations : local variables to MySubtraction()
    int a, b, subtraction;

    // code
    printf("\n\n");
    printf("Enter integer value for 'A' for subtraction : ");
    scanf("%d", &a);

    printf("\n\n");
    printf("Enter integer value for 'B' for subtraction : ");
    scanf("%d", &b);

    subtraction = a - b;
    return (subtraction);
}

// *** Function definition of MyMultiplication() ***
void MyMultiplication(int a, int b) // function definition
{
    // variable declarations : local variables to MyMultiplication()
    int multiplication;

    // code
    multiplication = a * b;

    printf("\n\n");
    printf("Multiplication of %d and %d = %d\n\n", a, b, multiplication);
}

// *** Function definition of MyDivision() ***
int MyDivision(int a, int b) // function definition
{
    // variable declarations : local variables to MyDivision()
    int division_quotient;

    // code
    if (a > b)
        division_quotient = a / b;
    else
        division_quotient = b / a;

    return (division_quotient);
}