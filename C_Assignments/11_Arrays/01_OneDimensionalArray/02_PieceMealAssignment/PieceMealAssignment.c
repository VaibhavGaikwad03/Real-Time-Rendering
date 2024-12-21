#include <stdio.h>

int main(void)
{
    // variable declarations
    int iArrayOne_vtg[10];
    int iArrayTwo_vtg[10];

    // code

    // ****** iArrayone[] ******
    iArrayOne_vtg[0] = 3;
    iArrayOne_vtg[1] = 6;
    iArrayOne_vtg[2] = 9;
    iArrayOne_vtg[3] = 12;
    iArrayOne_vtg[4] = 15;
    iArrayOne_vtg[5] = 18;
    iArrayOne_vtg[6] = 21;
    iArrayOne_vtg[7] = 24;
    iArrayOne_vtg[8] = 27;
    iArrayOne_vtg[9] = 30;

    printf("\n\n");
    printf("Piece-meal (hard-coded) assignment and display of elements to array 'iArrayone_vtg[]':   \n\n");
    printf("1st element of array 'iArrayone_vtg[]' or element at 0th index of array 'iArrayone_vtg[]'   = %d\n", iArrayOne_vtg[0]);
    printf("2nd element of array 'iArrayone_vtg[]' or element at 1st index of array 'iArrayone_vtg[]'   = %d\n", iArrayOne_vtg[1]);
    printf("3rd element of array 'iArrayone_vtg[]' or element at 2nd index of array 'iArrayone_vtg[]'   = %d\n", iArrayOne_vtg[2]);
    printf("4th element of array 'iArrayone_vtg[]' or element at 3rd index of array 'iArrayone_vtg[]'   = %d\n", iArrayOne_vtg[3]);
    printf("5th element of array 'iArrayone_vtg[]' or element at 4th index of array 'iArrayone_vtg[]'   = %d\n", iArrayOne_vtg[4]);
    printf("6th element of array 'iArrayone_vtg[]' or element at 5th index of array 'iArrayone_vtg[]'   = %d\n", iArrayOne_vtg[5]);
    printf("7th element of array 'iArrayone_vtg[]' or element at 6th index of array 'iArrayone_vtg[]'   = %d\n", iArrayOne_vtg[6]);
    printf("8th element of array 'iArrayone_vtg[]' or element at 7th index of array 'iArrayone_vtg[]'   = %d\n", iArrayOne_vtg[7]);
    printf("9th element of array 'iArrayone_vtg[]' or element at 8th index of array 'iArrayone_vtg[]'   = %d\n", iArrayOne_vtg[8]);
    printf("10th element of array 'iArrayone_vtg[]' or element at 9th index of array 'iArrayone_vtg[]'   = %d\n\n", iArrayOne_vtg[9]);

    // ****** iArrayTwo[] ******
    printf("\n\n");
    printf("Enter 1st element of array 'iArrayTwo_vtg[]' : ");
    scanf("%d", &iArrayTwo_vtg[0]);
    printf("Enter 2nd element of array 'iArrayTwo_vtg[]' : ");
    scanf("%d", &iArrayTwo_vtg[1]);
    printf("Enter 3rd element of array 'iArrayTwo_vtg[]' : ");
    scanf("%d", &iArrayTwo_vtg[2]);
    printf("Enter 4th element of array 'iArrayTwo_vtg[]' : ");
    scanf("%d", &iArrayTwo_vtg[3]);
    printf("Enter 5th element of array 'iArrayTwo_vtg[]' : ");
    scanf("%d", &iArrayTwo_vtg[4]);
    printf("Enter 6th element of array 'iArrayTwo_vtg[]' : ");
    scanf("%d", &iArrayTwo_vtg[5]);
    printf("Enter 7th element of array 'iArrayTwo_vtg[]' : ");
    scanf("%d", &iArrayTwo_vtg[6]);
    printf("Enter 8th element of array 'iArrayTwo_vtg[]' : ");
    scanf("%d", &iArrayTwo_vtg[7]);
    printf("Enter 9th element of array 'iArrayTwo_vtg[]' : ");
    scanf("%d", &iArrayTwo_vtg[8]);
    printf("Enter 10th element of array 'iArrayTwo_vtg[]' : ");
    scanf("%d", &iArrayTwo_vtg[9]);

    printf("\n\n");
    printf("Piece-meal (user input) assignment and display of elements to array 'iArrayTwo_vtg[]' :   \n\n");
    printf("1st element of array 'iArrayTwo_vtg[]' or element at 0th index of array 'iArrayTwo_vtg[]'   = %d\n", iArrayTwo_vtg[0]);
    printf("2nd element of array 'iArrayTwo_vtg[]' or element at 1st index of array 'iArrayTwo_vtg[]'   = %d\n", iArrayTwo_vtg[1]);
    printf("3rd element of array 'iArrayTwo_vtg[]' or element at 2nd index of array 'iArrayTwo_vtg[]'   = %d\n", iArrayTwo_vtg[2]);
    printf("4th element of array 'iArrayTwo_vtg[]' or element at 3rd index of array 'iArrayTwo_vtg[]'   = %d\n", iArrayTwo_vtg[3]);
    printf("5th element of array 'iArrayTwo_vtg[]' or element at 4th index of array 'iArrayTwo_vtg[]'   = %d\n", iArrayTwo_vtg[4]);
    printf("6th element of array 'iArrayTwo_vtg[]' or element at 5th index of array 'iArrayTwo_vtg[]'   = %d\n", iArrayTwo_vtg[5]);
    printf("7th element of array 'iArrayTwo_vtg[]' or element at 6th index of array 'iArrayTwo_vtg[]'   = %d\n", iArrayTwo_vtg[6]);
    printf("8th element of array 'iArrayTwo_vtg[]' or element at 7th index of array 'iArrayTwo_vtg[]'   = %d\n", iArrayTwo_vtg[7]);
    printf("9th element of array 'iArrayTwo_vtg[]' or element at 8th index of array 'iArrayTwo_vtg[]'   = %d\n", iArrayTwo_vtg[8]);
    printf("10th element of array 'iArrayTwo_vtg[]' or element at 9th index of array 'iArrayTwo_vtg[]'   = %d\n\n", iArrayTwo_vtg[9]);

    return (0);
}