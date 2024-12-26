#include <stdio.h>

struct MyData
{
    int i_vtg;
    float f_vtg;
    double d_vtg;
    char c_vtg;
};

main(void)
{
    // variable declarations
    struct MyData data_vtg;

    // code
    // Assigning Data Values To The Data Members Of 'struct MyData'
    data_vtg.i_vtg = 30;
    data_vtg.f_vtg = 11.45f;
    data_vtg.d_vtg = 1.2995;
    data_vtg.c_vtg = 'A';

    // Displaying Values Of The Data Members Of 'struct MyData'
    printf("\n\n");
    printf("DATA MEMBERS OF 'struct MyData' ARE : \n\n");
    printf("i = %d\n", data_vtg.i_vtg);
    printf("f = %f\n", data_vtg.f_vtg);
    printf("d = %lf\n", data_vtg.d_vtg);
    printf("c = %c\n\n", data_vtg.c_vtg);

    printf("\n\n");
    printf("ADDRESSES OF DATA MEMBERS OF 'struct MyData' ARE : \n\n");
    printf("'i' Occupies Addresses From %p\n", &data_vtg.i_vtg);
    printf("'f' Occupies Addresses From %p\n", &data_vtg.f_vtg);
    printf("'d' Occupies Addresses From %p\n", &data_vtg.d_vtg);
    printf("'c' Occupies Address %p\n\n", &data_vtg.c_vtg);

    printf("Starting Address Of 'struct MyData' variable 'data' = %p\n\n", &data_vtg);
    
    return (0);
}