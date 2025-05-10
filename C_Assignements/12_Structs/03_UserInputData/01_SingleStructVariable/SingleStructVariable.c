#include <stdio.h>
#include <conio.h>

struct MyData
{
    int i_vtg;
    float f_vtg;
    double d_vtg;
    char ch_vtg;
};

main(void)
{
    // variable declarations
    struct MyData data_vtg; // declaring a single struct variable

    // code
    // User Input For Values Of Data Members Of 'struct MyData'
    printf("\n\n");
    printf("Enter Integer Value For Data Member 'i' Of 'struct MyData' : \n");
    scanf("%d", &data_vtg.i_vtg);

    printf("Enter Floating - Point Value For Data Member 'f' Of 'struct MyData' : \n");
    scanf("%f", &data_vtg.f_vtg);

    printf("Enter 'Double' Value For Data Member 'd' Of 'struct MyData' : \n");
    scanf("%lf", &data_vtg.d_vtg);

    printf("Enter Character Value For Data Member 'c' Of 'struct MyData' : \n");
    data_vtg.ch_vtg = getch();

    // Display Values Of Data Members Of 'struct MyData'
    printf("\n\n");
    printf("DATA MEMBERS OF 'struct MyData' ARE : \n\n");
    printf("i = %d\n", data_vtg.i_vtg);
    printf("f = %f\n", data_vtg.f_vtg);
    printf("d = %lf\n", data_vtg.d_vtg);
    printf("c = %c\n\n", data_vtg.ch_vtg);

    return (0);
}