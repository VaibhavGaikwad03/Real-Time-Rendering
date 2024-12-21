#include <stdio.h>

int main(int argc, char *argv[], char *envp[])
{
    // Function prototypes or declarations
    int MyAddition(int, int);

    // Variable declarations
    int r_vtg;
    int num_01_vtg, num_02_vtg; // Variable declarations

    // Code
    num_01_vtg = 10; 
    num_02_vtg = 20;

    printf("\n\n");
    printf("%d + %d = %d\n", num_01_vtg, num_02_vtg, MyAddition(num_01_vtg, num_02_vtg));
    printf("\n\n");

    return 0;
}

// *** Function Definition of MyAddition ***
int MyAddition(int a_vtg, int b_vtg)
{
    // Function prototype
    int Add(int, int); // Declaration of Add function

    // Code
    return (Add(a_vtg, b_vtg)); // Return value of function Add() as return value of function MyAddition()
}

int Add(int x_vtg, int y_vtg)
{
    // Code
    return (x_vtg + y_vtg); 
}