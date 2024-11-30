#include <stdio.h>

int main(void)
{
    // variable declarations
    char option, ch = '\0';

    // code
    printf("\n\n");
    printf("Once the infinite loop begins, enter 'Q' or 'q' to quit the infinite for loop: \n\n");

    do
    {
        do
        {
            printf("\n");
            printf("In loop...\n");
            ch = getch();
        } while (ch != 'Q' && ch != 'q');
        printf("\n\n");
        printf("EXITING USER CONTROLLED INFINITE LOOP...");

        printf("\n\n");
        printf("DO YOU WANT TO BEGING USER CONTROLLED INFINITE LOOP AGAIN?...(Y/y - Yes, any other key - No): ");
        option = getch();
    } while (option == 'Y' || option == 'y');

    return 0;
}