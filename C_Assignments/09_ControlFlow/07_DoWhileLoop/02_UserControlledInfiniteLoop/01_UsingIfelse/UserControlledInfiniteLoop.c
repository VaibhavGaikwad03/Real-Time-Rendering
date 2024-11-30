#include <stdio.h>

int main(void)
{
    // variable declarations
    char option, ch = '\0';

    // code
    printf("\n\n");
    printf("Once the infinite loop begins, enter 'Q' or 'q' to quit the infinite for loop: \n\n");
    printf("Enter 'Y' or 'y' to initiate user controlled infinite loop: ");
    printf("\n\n");

    option = getch();
    if (option == 'Y' || option == 'y')
    {
        do
        {
            printf("In loop...\n");
            ch = getch();
            if (ch == 'Q' || ch == 'q')
                break; // user controlled exiting from infinite loop
        } while (1); // infinite loop

        printf("\n\n");
        printf("EXITING USER CONTROLLED INFINITE LOOP...");
        printf("\n\n");
    }
    else
    {
        printf("You must press 'Y' or 'y' to initiate the user controlled infinite loop... please try again...\n\n");
    }

    return 0;
}