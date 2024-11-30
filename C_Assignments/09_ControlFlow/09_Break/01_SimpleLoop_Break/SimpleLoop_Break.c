#include <stdio.h>
#include <conio.h>

int main(void)
{
    // variable declarations
    int i;
    char ch;

    // code 
    printf("\n\n");

    printf("Printing even numbers from 1 to 100 for every input. Exiting the loop when user enters character 'Q' or 'q': \n\n");
    printf("Enter character 'Q' or 'q' to exit loop: \n\n");

    for (i = 1 ; i <= 100; i++)
    {
        printf("\t%d\n", i);
        ch = getch();
        if (ch == 'Q' || ch == 'q')
        {
            break;
        }
    }

    printf("\n\n");
    printf("EXITING LOOP...");
    printf("\n\n");

    return (0);
}