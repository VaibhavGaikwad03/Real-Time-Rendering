#include <stdio.h>

int main(void)
{
    int i_vtg = 5;

    do
    {
        int j_vtg = 3;
        printf("i_vtg = %d\n", i_vtg);

        do
        {
            printf("j_vtg = %d\n", j_vtg);
            j_vtg--;
        } while (j_vtg >= 1);
        i_vtg--;
        printf("\n\n");
    } while (i_vtg >= 1);

    return (0);
}