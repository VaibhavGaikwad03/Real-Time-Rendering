#include <stdio.h>

int main(int argc, char *argv[], char *envp[])
{
    // function prototypes or declarations
    int MyAddition(int, int);

    // variable declarations
    int r_vtg;
    int num_01_vtg, num_02_vtg;
    int num_03_vtg, num_04_vtg;

    // code
    num_01_vtg = 10;
    num_02_vtg = 20;
    num_03_vtg = 30;
    num_04_vtg = 40;
    r_vtg = MyAddition(MyAddition(num_01_vtg, num_02_vtg), MyAddition(num_03_vtg, num_04_vtg)); // return value of MyAddition() is sent as parameter to another call to MyAddition()

    printf("\n\n");
    printf("%d + %d + %d + %d = %d\n", num_01_vtg, num_02_vtg, num_03_vtg, num_04_vtg, r_vtg);
    printf("\n\n");
    return (0);
}

// *** Function definition of MyAddition() ***
int MyAddition(int a, int b) // function definition
{
    // variable declaration
    int sum;
    // code
    sum = a + b;
    return (sum);
}