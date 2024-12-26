#include <stdio.h>

struct MyPoint
{
    int x_vtg;
    int y_vtg;
};

struct Rectangle
{
    struct MyPoint point_01_vtg, point_02_vtg;
};

int main(void)
{
    // variable declarations
    int length_vtg, breadth_vtg, area_vtg;
    struct Rectangle rect_vtg;

    // code
    printf("\n\n");
    printf("Enter leftmost x-coordinate of rectangle: ");
    scanf("%d", &rect_vtg.point_01_vtg.x_vtg);

    printf("\n\n");
    printf("Enter bottommost y-coordinate of rectangle: ");
    scanf("%d", &rect_vtg.point_01_vtg.y_vtg);

    printf("\n\n");
    printf("Enter rightmost x-coordinate of rectangle: ");
    scanf("%d", &rect_vtg.point_02_vtg.x_vtg);

    printf("\n\n");
    printf("Enter topmost y-coordinate of rectangle: ");
    scanf("%d", &rect_vtg.point_02_vtg.y_vtg);

    length_vtg = rect_vtg.point_02_vtg.y_vtg - rect_vtg.point_01_vtg.y_vtg;
    if (length_vtg < 0)
        length_vtg = length_vtg * -1;

    breadth_vtg = rect_vtg.point_02_vtg.x_vtg - rect_vtg.point_01_vtg.x_vtg;
    if (breadth_vtg < 0)
        breadth_vtg = breadth_vtg * -1;

    area_vtg = length_vtg * breadth_vtg;

    printf("\n\n");
    printf("Length of rectangle = %d\n\n", length_vtg);
    printf("Breadth of rectangle = %d\n\n", breadth_vtg);
    printf("Area of rectangle = %d\n\n", area_vtg);

    return (0);
}