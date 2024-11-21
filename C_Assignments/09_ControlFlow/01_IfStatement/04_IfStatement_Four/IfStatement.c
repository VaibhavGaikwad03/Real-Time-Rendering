#include <stdio.h>

int main(void)
{
    // variable declarations
    int age;

    // code
    printf("\n\n");
    printf("Enter age: ");
    scanf("%d", &age);

    if (age >= 18)
    {
        printf("You are eligible for voting!!!\n\n");
    }
    printf("You are NOT eligible for voting!!!\n\n");

    return (0);
}