#include <stdio.h>

int main(void)
{
    // function declarations
    void SwapNumbers(int *, int *);

    // variable declaration
    int a_vtg;
    int b_vtg;

    // code
    printf("\n\n");
    printf("Enter Value For 'A': ");
    scanf("%d", &a_vtg);

    printf("\n\n");
    printf("Enter Value For 'B': ");
    scanf("%d", &b_vtg);

    printf("\n\n");
    printf("****** BEFORE SWAPPING ******\n\n");
    printf("Value Of 'A' = %d\n\n", a_vtg);
    printf("Value Of 'B' = %d\n\n", b_vtg);

    SwapNumbers(&a_vtg, &b_vtg); //   ******   ARGUMENTS   PASSED   'BY   ADDRESS'   ...   ******

    printf("\n\n");
    printf("****** AFTER SWAPPING ******\n\n");
    printf("Value Of 'A' = %d\n\n", a_vtg);
    printf("Value Of 'B' = %d\n\n", b_vtg);

    return (0);
}

void SwapNumbers(int *x_vtg, int *y_vtg)
{
    // variable declarations
    int temp_vtg;

    // code
    printf("\n\n");
    printf("****** BEFORE SWAPPING ******\n\n");
    printf("Value Of 'X' = %d\n\n", *x_vtg);
    printf("Value Of 'Y' = %d\n\n", *y_vtg);

    temp_vtg = *x_vtg;
    *x_vtg = *y_vtg;
    *y_vtg = temp_vtg;

    printf("\n\n");
    printf("****** AFTER SWAPPING ******\n\n");
    printf("Value Of 'X' = %d\n\n", *x_vtg);
    printf("Value Of 'Y' = %d\n\n", *y_vtg);
}