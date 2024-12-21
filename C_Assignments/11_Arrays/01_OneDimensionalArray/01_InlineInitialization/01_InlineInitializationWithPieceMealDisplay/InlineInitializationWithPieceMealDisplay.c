#include <stdio.h>
int main(void)
{
    // variable declarations
    int iArray_vtg[] = {9, 30, 6, 12, 98, 95, 20, 23, 2, 45};
    int int_size_vtg;
    int iArray_size_vtg;
    int iArray_num_elements_vtg;

    float fArray_vtg[] = {1.2f, 2.3f, 3.4f, 4.5f, 5.6f, 6.7f, 7.8f, 8.9f};
    int float_size_vtg;
    int fArray_size_vtg;
    int fArray_num_elements_vtg;

    char cArray_vtg[] = {'A', 's', 'T', 'R', 'O', 'M', 'E', 'D', 'I', 'C', 'O', 'M', 'P'};
    int char_size_vtg;
    int cArray_size_vtg;
    int cArray_num_elements_vtg;

    // code
    printf("\n\n");
    printf("In-line initialization and piece-meal display of elements of array 'iArray[]': \n\n");
    printf("iArray_vtg[0] (1st element) = %d\n", iArray_vtg[0]);
    printf("iArray_vtg[1] (2nd element) = %d\n", iArray_vtg[1]);
    printf("iArray_vtg[2] (3rd element) = %d\n", iArray_vtg[2]);
    printf("iArray_vtg[3] (4th element) = %d\n", iArray_vtg[3]);
    printf("iArray_vtg[4] (5th element) = %d\n", iArray_vtg[4]);
    printf("iArray_vtg[5] (6th element) = %d\n", iArray_vtg[5]);
    printf("iArray_vtg[6] (7th element) = %d\n", iArray_vtg[6]);
    printf("iArray_vtg[7] (8th element) = %d\n", iArray_vtg[7]);
    printf("iArray_vtg[8] (9th element) = %d\n", iArray_vtg[8]);
    printf("iArray_vtg[9] (10th element) = %d\n\n", iArray_vtg[9]);

    int_size_vtg = sizeof(int);
    iArray_size_vtg = sizeof(iArray_vtg);
    iArray_num_elements_vtg = iArray_size_vtg / int_size_vtg;
    printf("Size of data type 'int' = %d bytes\n", int_size_vtg);
    printf("Number of elements in 'int' array 'iArray[]' = %d elements\n", iArray_num_elements_vtg);
    printf("Size of array 'iArray[]' (%d elements * %d bytes) = %d bytes\n\n", iArray_num_elements_vtg, int_size_vtg, iArray_size_vtg);

    printf("\n\n");
    printf("In-line initialization and piece-meal display of elements of array 'fArray[]': \n\n");
    printf("fArray_vtg[0] (1st element) = %f\n", fArray_vtg[0]);
    printf("fArray_vtg[1] (2nd element) = %f\n", fArray_vtg[1]);
    printf("fArray_vtg[2] (3rd element) = %f\n", fArray_vtg[2]);
    printf("fArray_vtg[3] (4th element) = %f\n", fArray_vtg[3]);
    printf("fArray_vtg[4] (5th element) = %f\n", fArray_vtg[4]);
    printf("fArray_vtg[5] (6th element) = %f\n", fArray_vtg[5]);
    printf("fArray_vtg[6] (7th element) = %f\n", fArray_vtg[6]);
    printf("fArray_vtg[7] (8th element) = %f\n", fArray_vtg[7]);
    printf("fArray_vtg[8] (9th element) = %f\n", fArray_vtg[8]);
    printf("fArray_vtg[9] (10th element) = %f\n\n", fArray_vtg[9]);

    float_size_vtg = sizeof(float);
    fArray_size_vtg = sizeof(fArray_vtg);
    fArray_num_elements_vtg = fArray_size_vtg / float_size_vtg;
    printf("Size of data type 'float' = %d bytes\n", float_size_vtg);
    printf("Number of elements in 'float' array 'fArray[]' = %d elements\n", fArray_num_elements_vtg);
    printf("Size of array 'fArray[]' (%d elements * %d bytes) = %d bytes\n\n", fArray_num_elements_vtg, float_size_vtg, fArray_size_vtg);

    printf("\n\n");
    printf("In-line initialization and piece-meal display of elements of array 'cArray[]': \n\n");
    printf("cArray_vtg[0] (1st element) = %c\n", cArray_vtg[0]);
    printf("cArray_vtg[1] (2nd element) = %c\n", cArray_vtg[1]);
    printf("cArray_vtg[2] (3rd element) = %c\n", cArray_vtg[2]);
    printf("cArray_vtg[3] (4th element) = %c\n", cArray_vtg[3]);
    printf("cArray_vtg[4] (5th element) = %c\n", cArray_vtg[4]);
    printf("cArray_vtg[5] (6th element) = %c\n", cArray_vtg[5]);
    printf("cArray_vtg[6] (7th element) = %c\n", cArray_vtg[6]);
    printf("cArray_vtg[7] (8th element) = %c\n", cArray_vtg[7]);
    printf("cArray_vtg[8] (9th element) = %c\n", cArray_vtg[8]);
    printf("cArray_vtg[9] (10th element) = %c\n", cArray_vtg[9]);
    printf("cArray_vtg[10] (11th element) = %c\n", cArray_vtg[10]);
    printf("cArray_vtg[11] (12th element) = %c\n", cArray_vtg[11]);
    printf("cArray_vtg[12] (13th element) = %c\n\n", cArray_vtg[12]);

    char_size_vtg = sizeof(char);
    cArray_size_vtg = sizeof(cArray_vtg);
    cArray_num_elements_vtg = cArray_size_vtg / char_size_vtg;
    printf("Size of data type 'char' = %d bytes\n", char_size_vtg);
    printf("Number of elements in 'char' array 'cArray[]' = %d elements\n", cArray_num_elements_vtg);
    printf("Size of array 'cArray[]' (%d elements * %d bytes) = %d bytes\n\n", cArray_num_elements_vtg, char_size_vtg, cArray_size_vtg);

    return (0);
}