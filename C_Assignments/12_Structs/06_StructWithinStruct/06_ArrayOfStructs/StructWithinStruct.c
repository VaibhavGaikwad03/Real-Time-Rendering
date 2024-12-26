#include <stdio.h>

struct MyNumber
{
    int num;
    int num_table[10];
};

struct NumTables
{
    struct MyNumber n_vtg;
};

int main(void)
{
    // variable declarations
    struct NumTables tables_vtg[10]; // an array of 10 'struct NumTables'
    int i_vtg, j_vtg;

    // code
    for (i_vtg = 0; i_vtg < 10; i_vtg++)
    {
        tables_vtg[i_vtg].n_vtg.num = (i_vtg + 1);
    }

    for (i_vtg = 0; i_vtg < 10; i_vtg++)
    {
        printf("\n\n");
        printf("Tables of %d: \n\n", tables_vtg[i_vtg].n_vtg.num);

        for (j_vtg = 0; j_vtg < 10; j_vtg++)
        {
            tables_vtg[i_vtg].n_vtg.num_table[j_vtg] = tables_vtg[i_vtg].n_vtg.num * (j_vtg + 1);
            printf("%d * %d = %d\n", tables_vtg[i_vtg].n_vtg.num, (j_vtg + 1), tables_vtg[i_vtg].n_vtg.num_table[j_vtg]);
        }
    }

    return (0);
}