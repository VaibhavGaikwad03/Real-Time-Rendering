#include <stdio.h>

int main(void)
{
    // variable declarations
    int num_month;

    // code
    printf("\n\n");

    printf("Enter number of month (1 to 12): ");
    scanf("%d", &num_month);

    printf("\n\n");

    if (num_month == 1)
        printf("Month number %d is JANUARY!!!\n\n", num_month);

    else if (num_month == 2)
        printf("Month number %d is FEBRUARY!!!\n\n", num_month);

    else if (num_month == 3)
        printf("Month number %d is MARCH!!!\n\n", num_month);

    else if (num_month == 4)
        printf("Month number %d is APRIL!!!\n\n", num_month);

    else if (num_month == 5)
        printf("Month number %d is MAY!!!\n\n", num_month);

    else if (num_month == 6)
        printf("Month number %d is JUNE!!!\n\n", num_month);

    else if (num_month == 7)
        printf("Month number %d is JULY!!!\n\n", num_month);

    else if (num_month == 8)
        printf("Month number %d is AUGUST!!!\n\n", num_month);

    else if (num_month == 9)
        printf("Month number %d is SEPTEMBER!!!\n\n", num_month);

    else if (num_month == 10)
        printf("Month number %d is OCTOBER!!!\n\n", num_month);

    else if (num_month == 11)
        printf("Month number %d is NOVEMBER!!!\n\n", num_month);

    else if (num_month == 12)
        printf("Month number %d is DECEMBER!!!\n\n", num_month);

    else
        printf("Invalid month number %d entered!!! Please try again...\n\n", num_month);

    printf("Switch case block complete!!!\n");

    return (0);
}