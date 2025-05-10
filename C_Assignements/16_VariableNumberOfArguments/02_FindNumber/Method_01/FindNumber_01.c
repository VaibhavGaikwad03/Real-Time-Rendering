#include <stdio.h>
#include <stdarg.h>

#define NUM_TO_BE_FOUND 3
#define NUM_ELEMENTS 10

int main(void)
{
    // function prototypes
    void FindNumber_vtg(int, int, ...);

    // code
    printf("\n\n");

    FindNumber_vtg(NUM_TO_BE_FOUND, NUM_ELEMENTS, 3, 5, 9, 2, 3, 6, 9, 3, 1, 3);

    return (0);
}

void FindNumber_vtg(int num_to_be_found_vtg, int num_vtg, ...) // VARIADIC FUNCTION
{
    // variable declarations
    int count_vtg = 0;
    int n_vtg;
    va_list numbers_list_vtg;

    // code
    va_start(numbers_list_vtg, num_vtg);

    while (num_vtg)
    {
        n_vtg = va_arg(numbers_list_vtg, int);
        if (n_vtg == num_to_be_found_vtg)
            count_vtg++;
        num_vtg--;
    }

    if (count_vtg == 0)
        printf("Number %d Could Not Be Found !!!\n\n", num_to_be_found_vtg);
    else
        printf("Number %d Found %d Times !!!\n\n", num_to_be_found_vtg, count_vtg);

    va_end(numbers_list_vtg);
}