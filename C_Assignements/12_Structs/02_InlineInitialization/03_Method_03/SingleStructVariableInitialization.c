#include <stdio.h>

int main(void)
{
    // DEFINING STRUCT
    struct MyData
    {
        int i_vtg;
        float f_vtg;
        double d_vtg;
        char c_vtg;
    } data = {30, 4.5f, 11.451995, 'A'}; // Inline initialization of struct variable 'data' of type 'struct MyData'

    // code
    // Displaying values of the data members of 'struct MyData'
    printf("\n\n");
    printf("DATA MEMBERS OF 'struct MyData' ARE: \n\n");
    printf("i_vtg = %d\n", data.i_vtg);
    printf("f_vtg = %f\n", data.f_vtg);
    printf("d_vtg = %lf\n", data.d_vtg);
    printf("c_vtg = %c\n\n", data.c_vtg);

    return (0);
}