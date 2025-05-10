#include <stdio.h>
#include <stdarg.h>

int main(void)
{
    // function prototypes
    int CalculateSum(int, ...);

    // variable declarations
    int answer_vtg;

    // code
    printf("\n\n");

    answer_vtg = CalculateSum(5, 10, 20, 30, 40, 50);
    printf("Answer = %d\n\n", answer_vtg);

    answer_vtg = CalculateSum(10, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1);
    printf("Answer = %d\n\n", answer_vtg);

    answer_vtg = CalculateSum(0);
    printf("Answer = %d\n\n", answer_vtg);

    return (0);
}

int CalculateSum(int num_vtg, ...) // VARIADIC FUNCTION
{
    // variable declarations
    int sum_total_vtg = 0;
    int n_vtg;

    va_list numbers_list_vtg;

    // code
    va_start(numbers_list_vtg, num_vtg);

    while (num_vtg)
    {
        n_vtg = va_arg(numbers_list_vtg, int);
        sum_total_vtg = sum_total_vtg + n_vtg;
        num_vtg--;
    }

    va_end(numbers_list_vtg);

    return (sum_total_vtg);
}