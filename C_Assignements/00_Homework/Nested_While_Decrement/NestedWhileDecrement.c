#include <stdio.h>

int main(void)
{
    int i_vtg = 5;

    while (i_vtg >= 1)
    {
        int j_vtg = 3;
        printf("i_vtg = %d\n", i_vtg);
        while (j_vtg >= 1)
        {
            printf("j_vtg = %d\n", j_vtg);
            j_vtg--;
        }
        i_vtg--;
        printf("\n\n");
    }

    return (0);
}