#include <stdio.h>
#include <string.h> // Include string.h for strcpy function

// DEFINING STRUCT
struct MyPoint_vtg
{
    int x_vtg;
    int y_vtg;
} point_vtg; // declaring a single variable of type 'struct MyPoint' globally...

// DEFINING STRUCT
struct MyPointProperties_vtg
{
    int quadrant_vtg;
    char axis_location_vtg[10];
} point_properties_vtg; // declaring a single variable of type 'struct MyPointProperties' globally...

int main(void)
{
    // code
    // User Input For The Data Members Of 'struct MyPoint' variable 'point_A'
    printf("\n\n");
    printf("Enter x-coordinate for a point: ");
    scanf("%d", &point_vtg.x_vtg);
    printf("Enter y-coordinate for a point: ");
    scanf("%d", &point_vtg.y_vtg);

    printf("\n\n");
    printf("Point co-ordinates (x, y) are: (%d, %d) !!!\n\n", point_vtg.x_vtg, point_vtg.y_vtg);

    if (point_vtg.x_vtg == 0 && point_vtg.y_vtg == 0)
        printf("The point is the origin (%d, %d) !!   !\n", point_vtg.x_vtg, point_vtg.y_vtg);
    else // Atleast one of the two values (either 'X' or 'Y' or BOTH) is a non-zero value...
    {
        if (point_vtg.x_vtg == 0) // If 'X' IS ZERO...OBVIOUSLY 'Y' IS THE NON-ZERO VALUE
        {
            if (point_vtg.y_vtg < 0) // If 'Y' IS -ve
                strcpy(point_properties_vtg.axis_location_vtg, "Negative Y");
            if (point_vtg.y_vtg > 0) // If 'Y' IS +ve
                strcpy(point_properties_vtg.axis_location_vtg, "Positive Y");
            point_properties_vtg.quadrant_vtg = 0; // A point lying on any of the co-ordinate axes is NOT a part of ANY quadrant...
            printf("The point lies on the %s axis !!!\n\n", point_properties_vtg.axis_location_vtg);
        }
        else if (point_vtg.y_vtg == 0) // If 'Y' IS ZERO...OBVIOUSLY 'X' IS THE NON-ZERO VALUE.
        {
            if (point_vtg.x_vtg < 0) // If 'X' IS -ve
                strcpy(point_properties_vtg.axis_location_vtg, "Negative X");
            if (point_vtg.x_vtg > 0) // If 'X' IS +ve
                strcpy(point_properties_vtg.axis_location_vtg, "Positive X");
            point_properties_vtg.quadrant_vtg = 0; // A point lying on any of the co-ordinate axes is NOT a part of ANY quadrant...
            printf("The point lies on the %s axis !!!\n\n", point_properties_vtg.axis_location_vtg);
        }
        else // BOTH 'X' AND 'Y' ARE NON-ZERO
        {
            point_properties_vtg.axis_location_vtg[0] = '\0'; // A point lying in ANY of the 4 quadrants cannot be lying on any of the co-ordinate axes...
            if (point_vtg.x_vtg > 0 && point_vtg.y_vtg > 0)
                point_properties_vtg.quadrant_vtg = 1;           // 'X' IS +ve AND 'Y' IS +ve
            else if (point_vtg.x_vtg < 0 && point_vtg.y_vtg > 0) // 'X' IS -ve AND 'Y' IS +ve
                point_properties_vtg.quadrant_vtg = 2;
            else if (point_vtg.x_vtg < 0 && point_vtg.y_vtg < 0) // 'X' IS -ve AND 'Y' IS -ve
                point_properties_vtg.quadrant_vtg = 3;
            else
                point_properties_vtg.quadrant_vtg = 4; // 'X' IS +ve AND 'Y' IS -ve

            printf("The point lies in quadrant number %d !!!\n\n", point_properties_vtg.quadrant_vtg);
        }
    }

    return (0);
}