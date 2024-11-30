#include <stdio.h>

int main(void)
{
    // variable declarations
    int num;

    // code
    printf("\n\n");

    printf("Enter value for 'num': ");
    scanf("%d", &num);

    if (num < 0) // 'if' - 01
    {
        printf("Num = %d is less than 0 (NEGATIVE)!!!\n\n", num);
    }
    else // 'else' - 01
    {
        if ((num > 0) && (num <= 100)) // 'if' - 02
        {
            printf("Num = %d is between 0 and 100!!!\n\n", num);
        }
        else // 'else' - 02
        {
            if ((num > 100) && (num <= 200)) //'if' - 03
            {
                printf("Num = %d is between 100 and 200!!!\n\n", num);
            }
            else // 'else' - 03
            {
                if ((num > 200) && (num <= 300)) // 'if' - 04
                {
                    printf("Num = %d is between 200 and 300!!!\n\n", num);
                }
                else // 'else' - 04
                {
                    if ((num > 300) && (num <= 400)) // 'if' - 05
                    {
                        printf("Num = %d is between 300 and 400!!!\n\n", num);
                    }
                    else // 'else' - 05
                    {
                        if ((num > 400) && (num <= 500)) // 'if' - 06
                        {
                            printf("Num = %d is between 400 and 500!!!\n\n", num);
                        }
                        else // 'else' - 06
                        {
                            printf("Num = %d is greater than 500!!!\n\n", num);
                        } // closing brace of 'else' - 06
                    } // close brace of 'else' - 05
                } // close brace of 'else' - 04
            } // close brace of 'else' - 03
        } // close brace of 'else' - 02
    } // close brace of 'else' - 01

    return (0);
}