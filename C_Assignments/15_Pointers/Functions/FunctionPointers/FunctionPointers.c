#include <stdio.h>

int main(void)
{
    // function declarations
    int AddIntegers(int, int);
    int SubtractIntegers(int, int);
    float AddFloats(float, float);

    // variable declaration
    typedef int (*AddIntsFnPtr)(int, int);
    AddIntsFnPtr ptrAddTwoIntegers_vtg = NULL;
    AddIntsFnPtr ptrFunc_vtg = NULL;

    typedef float (*AddFloatsFnPtr)(float, float);
    AddFloatsFnPtr ptrAddTwoFloats_vtg = NULL;

    int iAnswer_vtg = 0;
    float fAnswer_vtg = 0.0f;

    // code
    ptrAddTwoIntegers_vtg = AddIntegers;
    iAnswer_vtg = ptrAddTwoIntegers_vtg(9, 30);
    printf("\n\n");
    printf("Sum of integers = %d\n\n", iAnswer_vtg);

    ptrFunc_vtg = SubtractIntegers;
    iAnswer_vtg = ptrFunc_vtg(9, 30);
    printf("\n\n");
    printf("Subtraction of integers = %d\n\n", iAnswer_vtg);

    ptrAddTwoFloats_vtg = AddFloats;
    fAnswer_vtg = ptrAddTwoFloats_vtg(11.45f, 8.2f);
    printf("\n\n");
    printf("Sum of floating-point numbers = %f\n\n", fAnswer_vtg);

    return (0);
}

AddIntegers(int a_vtg, int b_vtg) // varibale declarations
{
    // varibale declarations
    int c_vtg;

    // code
    c_vtg = a_vtg + b_vtg;

    return (c_vtg);
}

SubtractIntegers(int a_vtg, int b_vtg)
{
    // varibale declarations
    int c_vtg;

    // code
    if (a_vtg > b_vtg)
        c_vtg = a_vtg - b_vtg;
    else
        c_vtg = b_vtg - a_vtg;

    return (c_vtg);
}

float AddFloats(float f_num1_vtg, float f_num2_vtg)
{
    // varibale declarations
    float ans_vtg;

    // code
    ans_vtg = f_num1_vtg + f_num2_vtg;

    return (ans_vtg);
}