#include <stdio.h>

struct MyPoint
{
    int x_vtg;
    int y_vtg;
};

int main(void)
{
    // variable declarations
    struct MyPoint point_A_vtg, point_B_vtg, point_C_vtg, point_D_vtg, point_E_vtg; // declaring a 5 ? struct variables

    // User  Input For The Data Members Of 'struct MyPoint' variable 'point_A_vtg'
    printf("\n\n");
    printf("Enter X-Coordinate For Point 'A' : ");
    scanf("%d", &point_A_vtg.x_vtg);
    printf("Enter Y-Coordinate For Point 'A' : ");
    scanf("%d", &point_A_vtg.y_vtg);

    // User  Input For The Data Members Of 'struct MyPoint' variable 'point_B_vtg'
    printf("\n\n");
    printf("Enter X-Coordinate For Point 'B' : ");
    scanf("%d", &point_B_vtg.x_vtg);
    printf("Enter Y-Coordinate For Point 'B' : ");
    scanf("%d", &point_B_vtg.y_vtg);

    // User  Input For The Data Members Of 'struct MyPoint' variable 'point_C_vtg'
    printf("\n\n");
    printf("Enter X-Coordinate For Point 'C' : ");
    scanf("%d", &point_C_vtg.x_vtg);
    printf("Enter Y-Coordinate For Point 'C' : ");
    scanf("%d", &point_C_vtg.y_vtg);

    // User  Input For The Data Members Of 'struct MyPoint' variable 'point_D_vtg'
    printf("\n\n");
    printf("Enter X-Coordinate For Point 'D' : ");
    scanf("%d", &point_D_vtg.x_vtg);
    printf("Enter Y-Coordinate For Point 'D' : ");
    scanf("%d", &point_D_vtg.y_vtg);

    // User  Input For The Data Members Of 'struct MyPoint' variable 'point_E_vtg'
    printf("\n\n");
    printf("Enter X-Coordinate For Point 'E' : ");
    scanf("%d", &point_E_vtg.x_vtg);
    printf("Enter Y-Coordinate For Point 'E' : ");
    scanf("%d", &point_E_vtg.y_vtg);

    // Displaying Values Of The Data Members Of 'struct MyPoint' (all variables)
    printf("\n\n");
    printf("Co-ordinates (x, y) Of Point 'A' Are : (%d, %d)\n\n", point_A_vtg.x_vtg, point_A_vtg.y_vtg);
    printf("Co-ordinates (x, y) Of Point 'B' Are : (%d, %d)\n\n", point_B_vtg.x_vtg, point_B_vtg.y_vtg);
    printf("Co-ordinates (x, y) Of Point 'C' Are : (%d, %d)\n\n", point_C_vtg.x_vtg, point_C_vtg.y_vtg);
    printf("Co-ordinates (x, y) Of Point 'D' Are : (%d, %d)\n\n", point_D_vtg.x_vtg, point_D_vtg.y_vtg);
    printf("Co-ordinates (x, y) Of Point 'E' Are : (%d, %d)\n\n", point_E_vtg.x_vtg, point_E_vtg.y_vtg);

    return (0);
}