#include <stdio.h>

int main(void)
{
    // Defining struct
    struct MyData
    {
        int i_vtg;
        float f_vtg;
        double d_vtg;
        char c_vtg;
    } data_vtg; // Declaring a single struct variable of type 'struct MyData' globally ...

    // Variable declarations
    int i_size_vtg;
    int f_size_vtg;
    int d_size_vtg;
    int struct_MyData_size_vtg;

    // Code
    // Assigning data values to the data members of 'struct MyData'
    data_vtg.i_vtg = 30;
    data_vtg.f_vtg = 11.45f;
    data_vtg.d_vtg = 1.2995;

    // Displaying values of the data members of 'struct MyData'
    printf("\n\n");
    printf("DATA MEMBERS OF 'struct MyData' ARE : \n\n");
    printf("i = %d\n", data_vtg.i_vtg);
    printf("f = %f\n", data_vtg.f_vtg);
    printf("d = %lf\n", data_vtg.d_vtg);

    // Calculating sizes (in bytes) of the data members of 'struct MyData'
    i_size_vtg = sizeof(data_vtg.i_vtg);
    f_size_vtg = sizeof(data_vtg.f_vtg);
    d_size_vtg = sizeof(data_vtg.d_vtg);

    // Displaying sizes (in bytes) of the data members of 'struct MyData'
    printf("\n\n");
    printf("SIZES (in bytes) OF DATA MEMBERS OF 'struct MyData' ARE : \n\n");
    printf("Size of 'i' = %d bytes\n", i_size_vtg);
    printf("Size of 'f' = %d bytes\n", f_size_vtg);
    printf("Size of 'd' = %d bytes\n", d_size_vtg);

    // Calculating size (in bytes) of the entire 'struct MyData'
    struct_MyData_size_vtg = sizeof(struct MyData); // Can also give struct name -> T sizeof(MyData)

    // Displaying sizes (in bytes) of the entire 'struct MyData'
    printf("\n\n");
    printf("Size of 'struct MyData' : %d bytes\n\n", struct_MyData_size_vtg);

    return (0);
}