#include <stdio.h>

int main(void)
{
    // variable declarations
    int a_vtg;
    int b_vtg;
    int x_vtg;

    // code
    printf("\n\n");
    printf("Enter a number: ");
    scanf("%d", &a_vtg);
    printf("\n\n");
    printf("Enter another number: ");
    scanf("%d", &b_vtg);
    printf("\n\n");

    // since, in all the following 5 cases, the operand on the left 'a' is getting repeated immediately on the right (e.g: a = a + b or a = a - b),
    // we are using compound assignment operators +=, -=, *=, /= and %=
    // since, 'a' will be assigned the value of (a + b) at the expression (a += b), we must save the original value of 'a' to another variable (x)
    x_vtg = a_vtg;
    a_vtg += b_vtg; // a = a + b
    printf("Addition of a = %d and b = %d gives %d.\n", x_vtg, b_vtg, a_vtg);

    // value of 'a' altered in the above expression is used here...
    // since, 'a' will be assigned the value of (a - b) at the expression (a -= b), we must save the original value of 'a' to another variable (x)
    x_vtg = a_vtg;
    a_vtg -= b_vtg; // a = a - b
    printf("Subtraction of a = %d and b = %d gives %d.\n", x_vtg, b_vtg, a_vtg);

    // value of 'a' altered in the above expression is used here...
    // since, 'a' will be assigned the value of (a * b) at the expression (a *= b), we must save the original value of 'a' to another variable (x)
    x_vtg = a_vtg;
    a_vtg *= b_vtg; // a = a * b
    printf("Multiplication of a = %d and b = %d gives %d.\n", x_vtg, b_vtg, a_vtg);

    // value of 'a' altered in the above expression is used here...
    // since, 'a' will be assigned the value of (a / b) at the expression (a /= b), we must save the original value of 'a' to another variable (x)
    x_vtg = a_vtg;
    a_vtg /= b_vtg; // a = a / b
    printf("Division of a = %d and b = %d gives quotient %d.\n", x_vtg, b_vtg, a_vtg);

    // value of 'a' altered in the above expression is used here...
    // since, 'a' will be assigned the value of (a % b) at the expression (a %= b), we must save the original value of 'a' to another variable (x)
    x_vtg = a_vtg;
    a_vtg %= b_vtg; // a = a % b
    printf("Division of a = %d and b = %d gives remainder %d.\n", x_vtg, b_vtg, a_vtg);

    printf("\n\n");

    return (0);
}