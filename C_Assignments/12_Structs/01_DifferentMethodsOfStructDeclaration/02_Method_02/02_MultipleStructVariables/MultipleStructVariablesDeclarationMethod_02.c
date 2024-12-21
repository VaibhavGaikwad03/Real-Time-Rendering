#include <stdio.h>

// Defining struct ...
struct MyPoint
{
    int x_vtg;
    int y_vtg;
};

struct MyPoint point_A_vtg, point_B_vtg, point_C_vtg, point_D_vtg, point_E_vtg; // Declaring 5 struct variables of type 'struct MyPoint' globally...

int main(void)
{
    // Code
    // Assigning data values to the data members of 'struct MyPoint' variable 'point_A_vtg'
    point_A_vtg.x_vtg = 3;
    point_A_vtg.y_vtg = 0;

    // Assigning data values to the data members of 'struct MyPoint' variable 'point_B_vtg'
    point_B_vtg.x_vtg = 1;
    point_B_vtg.y_vtg = 2;

    // Assigning data values to the data members of 'struct MyPoint' variable 'point_C_vtg'
    point_C_vtg.x_vtg = 9;
    point_C_vtg.y_vtg = 6;

    // Assigning data values to the data members of 'struct MyPoint' variable 'point_D_vtg'
    point_D_vtg.x_vtg = 8;
    point_D_vtg.y_vtg = 2;

    // Assigning data values to the data members of 'struct MyPoint' variable 'point_E_vtg'
    point_E_vtg.x_vtg = 11;
    point_E_vtg.y_vtg = 8;

    // Displaying values of the data members of 'struct MyPoint' (all variables)
    printf("\n\n");
    printf("Co-ordinates (x, y) of point 'A' are: (%d, %d)\n\n", point_A_vtg.x_vtg, point_A_vtg.y_vtg);
    printf("Co-ordinates (x, y) of point 'B' are: (%d, %d)\n\n", point_B_vtg.x_vtg, point_B_vtg.y_vtg);
    printf("Co-ordinates (x, y) of point 'C' are: (%d, %d)\n\n", point_C_vtg.x_vtg, point_C_vtg.y_vtg);
    printf("Co-ordinates (x, y) of point 'D' are: (%d, %d)\n\n", point_D_vtg.x_vtg, point_D_vtg.y_vtg);
    printf("Co-ordinates (x, y) of point 'E' are: (%d, %d)\n\n", point_E_vtg.x_vtg, point_E_vtg.y_vtg);

    return (0);
}