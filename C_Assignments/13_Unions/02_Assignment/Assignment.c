#include <stdio.h>

union MyUnion
{
    int i_vtg;
    float f_vtg;
    double d_vtg;
    char c_vtg;
};

main(void)
{
    // variable declarations
    union MyUnion u1_vtg, u2_vtg;

    // code
    //    ***   MyUnion   u2   ***
    printf("\n\n");
    printf("Members of union u1_vtg are: \n\n");

    u1_vtg.i_vtg = 6;
    u1_vtg.f_vtg = 1.2f;
    u1_vtg.d_vtg = 8.333333;
    u1_vtg.c_vtg = 'S';

    printf("u1_vtg.i_vtg = %d\n\n", u1_vtg.i_vtg);
    printf("u1_vtg.f_vtg = %f\n\n", u1_vtg.f_vtg);
    printf("u1_vtg.d_vtg = %lf\n\n", u1_vtg.d_vtg);
    printf("u1_vtg.c_vtg = %c\n\n", u1_vtg.c_vtg);

    printf("Addresses of members of union u1_vtg are: \n\n");
    printf("u1_vtg.i_vtg = %p\n\n", &u1_vtg.i_vtg);
    printf("u1_vtg.f_vtg = %p\n\n", &u1_vtg.f_vtg);
    printf("u1_vtg.d_vtg = %p\n\n", &u1_vtg.d_vtg);
    printf("u1_vtg.c_vtg = %p\n\n", &u1_vtg.c_vtg);
    printf("MyUnion u1_vtg = %p\n\n", &u1_vtg);

    //   ***   MyUnion   u2   ***
    printf("\n\n");
    printf("Members of union u2_vtg are: \n\n");
    u2_vtg.i_vtg = 3;
    printf("u2_vtg.i_vtg = %d\n\n", u2_vtg.i_vtg);
    u2_vtg.f_vtg = 4.5f;
    printf("u2_vtg.f_vtg = %f\n\n", u2_vtg.f_vtg);
    u2_vtg.d_vtg = 5.12764;
    printf("u2_vtg.d_vtg = %lf\n\n", u2_vtg.d_vtg);
    u2_vtg.c_vtg = 'A';
    printf("u2_vtg.c_vtg = %c\n\n", u2_vtg.c_vtg);

    printf("Addresses of members of union u2_vtg are: \n\n");
    printf("u2_vtg.i_vtg = %p\n\n", &u2_vtg.i_vtg);
    printf("u2_vtg.f_vtg = %p\n\n", &u2_vtg.f_vtg);
    printf("u2_vtg.d_vtg = %p\n\n", &u2_vtg.d_vtg);
    printf("u2_vtg.c_vtg = %p\n\n", &u2_vtg.c_vtg);

    printf("MyUnion u2_vtg = %p\n\n", &u2_vtg);

    return (0);
}