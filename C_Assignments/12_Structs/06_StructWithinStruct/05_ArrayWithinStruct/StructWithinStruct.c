#include <stdio.h>

struct MyNumber
{
    int num_vtg;
    int num_table_vtg[10];
};

struct NumTables
{
    struct MyNumber a_vtg;
    struct MyNumber b_vtg;
    struct MyNumber c_vtg;
};

int main(void)
{
    // variable declarations
    struct NumTables tables_vtg;
    int i_vtg;

    // code
    tables_vtg.a_vtg.num_vtg = 2;
    for (i_vtg = 0; i_vtg < 10; i_vtg++)
        tables_vtg.a_vtg.num_table_vtg[i_vtg] = tables_vtg.a_vtg.num_vtg * (i_vtg + 1);

    printf("\n\n");
    printf("Table of %d : \n\n", tables_vtg.a_vtg.num_vtg);
    for (i_vtg = 0; i_vtg < 10; i_vtg++)
        printf("%d * %d = %d\n", tables_vtg.a_vtg.num_vtg, (i_vtg + 1), tables_vtg.a_vtg.num_table_vtg[i_vtg]);

    tables_vtg.b_vtg.num_vtg = 3;
    for (i_vtg = 0; i_vtg < 10; i_vtg++)
        tables_vtg.b_vtg.num_table_vtg[i_vtg] = tables_vtg.b_vtg.num_vtg * (i_vtg + 1);

    printf("\n\n");
    printf("Table of %d : \n\n", tables_vtg.b_vtg.num_vtg);
    for (i_vtg = 0; i_vtg < 10; i_vtg++)
        printf("%d * %d = %d\n", tables_vtg.b_vtg.num_vtg, (i_vtg + 1), tables_vtg.b_vtg.num_table_vtg[i_vtg]);

    tables_vtg.c_vtg.num_vtg = 4;
    for (i_vtg = 0; i_vtg < 10; i_vtg++)
        tables_vtg.c_vtg.num_table_vtg[i_vtg] = tables_vtg.c_vtg.num_vtg * (i_vtg + 1);

    printf("\n\n");
    printf("Table of %d : \n\n", tables_vtg.c_vtg.num_vtg);
    for (i_vtg = 0; i_vtg < 10; i_vtg++)
        printf("%d * %d = %d\n", tables_vtg.c_vtg.num_vtg, (i_vtg + 1), tables_vtg.c_vtg.num_table_vtg[i_vtg]);

    return (0);
}