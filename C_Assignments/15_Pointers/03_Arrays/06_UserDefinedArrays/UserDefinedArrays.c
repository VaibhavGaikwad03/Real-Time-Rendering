#include <stdio.h>
#include <stdlib.h>

#define INT_SIZE sizeof(int)
#define FLOAT_SIZE sizeof(float)
#define DOUBLE_SIZE sizeof(double)
#define CHAR_SIZE sizeof(char)

int main(void)
{
    // Variable declarations
    int *ptr_iArray_vtg = NULL;
    unsigned int intArrayLength_vtg = 0;

    float *ptr_fArray_vtg = NULL;
    unsigned int floatArrayLength_vtg = 0;

    double *ptr_dArray_vtg = NULL;
    unsigned int doubleArrayLength_vtg = 0;

    char *ptr_cArray_vtg = NULL;
    unsigned int charArrayLength_vtg = 0;

    int i_vtg;

    // ****** INTEGER ARRAY *******
    printf("\n\n");
    printf("Enter the number of elements you want in the integer array: ");
    scanf("%u", &intArrayLength_vtg);

    ptr_iArray_vtg = (int *)malloc(INT_SIZE * intArrayLength_vtg);
    if (ptr_iArray_vtg == NULL)
    {
        printf("\n\n");
        printf("Memory allocation for integer array failed! Exiting now...\n\n");
        exit(0);
    }
    else
    {
        printf("\n\n");
        printf("Memory allocation for integer array succeeded!\n\n");
    }

    printf("\n\n");
    printf("Enter the %d integer elements to fill up the integer array:\n\n", intArrayLength_vtg);
    for (i_vtg = 0; i_vtg < intArrayLength_vtg; i_vtg++)
        scanf("%d", (ptr_iArray_vtg + i_vtg));

    // ****** FLOAT ARRAY *******
    printf("\n\n");
    printf("Enter the number of elements you want in the 'float' array: ");
    scanf("%u", &floatArrayLength_vtg);

    ptr_fArray_vtg = (float *)malloc(FLOAT_SIZE * floatArrayLength_vtg);
    if (ptr_fArray_vtg == NULL)
    {
        printf("\n\n");
        printf("Memory allocation for floating-point array failed! Exiting now...\n\n");
        exit(0);
    }
    else
    {
        printf("\n\n");
        printf("Memory allocation for floating-point array succeeded!\n\n");
    }

    printf("\n\n");
    printf("Enter the %d floating-point elements to fill up the 'float' array:\n\n", floatArrayLength_vtg);
    for (i_vtg = 0; i_vtg < floatArrayLength_vtg; i_vtg++)
        scanf("%f", (ptr_fArray_vtg + i_vtg));

    // ****** DOUBLE ARRAY *******
    printf("\n\n");
    printf("Enter the number of elements you want in the 'double' array: ");
    scanf("%u", &doubleArrayLength_vtg);

    ptr_dArray_vtg = (double *)malloc(DOUBLE_SIZE * doubleArrayLength_vtg);
    if (ptr_dArray_vtg == NULL)
    {
        printf("\n\n");
        printf("Memory allocation for 'double' array failed! Exiting now...\n\n");
        exit(0);
    }
    else
    {
        printf("\n\n");
        printf("Memory allocation for 'double' array succeeded!\n\n");
    }

    printf("\n\n");
    printf("Enter the %d double elements to fill up the 'double' array:\n\n", doubleArrayLength_vtg);
    for (i_vtg = 0; i_vtg < doubleArrayLength_vtg; i_vtg++)
        scanf("%lf", (ptr_dArray_vtg + i_vtg));

    // ****** CHAR ARRAY *******
    printf("\n\n");
    printf("Enter the number of elements you want in the character array: ");
    scanf("%u", &charArrayLength_vtg);

    ptr_cArray_vtg = (char *)malloc(CHAR_SIZE * charArrayLength_vtg);
    if (ptr_cArray_vtg == NULL)
    {
        printf("\n\n");
        printf("Memory allocation for character array failed! Exiting now...\n\n");
        exit(0);
    }
    else
    {
        printf("\n\n");
        printf("Memory allocation for character array succeeded!\n\n");
    }

    printf("\n\n");
    printf("Enter the %d character elements to fill up the character array:\n\n", charArrayLength_vtg);
    for (i_vtg = 0; i_vtg < charArrayLength_vtg; i_vtg++)
    {
        *(ptr_cArray_vtg + i_vtg) = getch(); // Use getchar to capture character input
    }

    // DISPLAY OF ARRAYS **********

    // ****** INTEGER ARRAY ******
    printf("\n\n");
    printf("The integer array entered by you and consisting of %d elements is as follows:\n\n", intArrayLength_vtg);
    for (i_vtg = 0; i_vtg < intArrayLength_vtg; i_vtg++)
        printf(" %d \t\t At address: %p\n", *(ptr_iArray_vtg + i_vtg), (ptr_iArray_vtg + i_vtg));

    // ****** FLOAT ARRAY ******
    printf("\n\n");
    printf("The float array entered by you and consisting of %d elements is as follows:\n\n", floatArrayLength_vtg);
    for (i_vtg = 0; i_vtg < floatArrayLength_vtg; i_vtg++)
        printf(" %f \t\t At address: %p\n", *(ptr_fArray_vtg + i_vtg), (ptr_fArray_vtg + i_vtg));

    // ****** DOUBLE ARRAY ******
    printf("\n\n");
    printf("The double array entered by you and consisting of %d elements is as follows:\n\n", doubleArrayLength_vtg);
    for (i_vtg = 0; i_vtg < doubleArrayLength_vtg; i_vtg++)
        printf(" %lf \t\t At address: %p\n", *(ptr_dArray_vtg + i_vtg), (ptr_dArray_vtg + i_vtg));

    // ****** CHARACTER ARRAY ******
    printf("\n\n");
    printf("The character array entered by you and consisting of %d elements is as follows:\n\n", charArrayLength_vtg);
    for (i_vtg = 0; i_vtg < charArrayLength_vtg; i_vtg++)
        printf(" %c \t\t At address: %p\n", *(ptr_cArray_vtg + i_vtg), (ptr_cArray_vtg + i_vtg));

    // FREEING MEMORY OCCUPIED BY ARRAYS (IN REVERSE ORDER OF ALLOCATION) ******
    if (ptr_cArray_vtg)
    {
        free(ptr_cArray_vtg);
        ptr_cArray_vtg = NULL;
        printf("\n\n");
        printf("Memory occupied by character array has been successfully freed!\n\n");
    }

    if (ptr_dArray_vtg)
    {
        free(ptr_dArray_vtg);
        ptr_dArray_vtg = NULL;
        printf("\n\n");
        printf("Memory occupied by 'double' array has been successfully freed!\n\n");
    }

    if (ptr_fArray_vtg)
    {
        free(ptr_fArray_vtg);
        ptr_fArray_vtg = NULL;
        printf("\n\n");
        printf("Memory occupied by floating-point array has been successfully freed!\n\n");
    }

    if (ptr_iArray_vtg)
    {
        free(ptr_iArray_vtg);
        ptr_iArray_vtg = NULL;
        printf("\n\n");
        printf("Memory occupied by integer array has been successfully freed!\n\n");
    }

    return 0;
}