#include <stdio.h>

int main(void)
{
    // Variable declarations
    int iArray_vtg[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100}; // Integer array
    int *ptr_iArray_vtg = NULL;                                   // Integer pointer

    // Code
    // ###### Using array name as a array i.e : Value of xth element of iArray : iArray[x] and address of xth element of iArray : &iArray[x] ######
    printf("\n\n");
    printf("*** Using array name as an array i.e : Value of xth element of iArray : iArray[x] and address of xth element of iArray : &iArray[x] ***\n\n");

    printf("Integer array elements and their addresses :\n\n");
    printf("iArray_vtg[0] = %d\t\t At address &iArray_vtg[0] : %p\n", iArray_vtg[0], &iArray_vtg[0]);
    printf("iArray_vtg[1] = %d\t\t At address &iArray_vtg[1] : %p\n", iArray_vtg[1], &iArray_vtg[1]);
    printf("iArray_vtg[2] = %d\t\t At address &iArray_vtg[2] : %p\n", iArray_vtg[2], &iArray_vtg[2]);
    printf("iArray_vtg[3] = %d\t\t At address &iArray_vtg[3] : %p\n", iArray_vtg[3], &iArray_vtg[3]);
    printf("iArray_vtg[4] = %d\t\t At address &iArray_vtg[4] : %p\n", iArray_vtg[4], &iArray_vtg[4]);
    printf("iArray_vtg[5] = %d\t\t At address &iArray_vtg[5] : %p\n", iArray_vtg[5], &iArray_vtg[5]);
    printf("iArray_vtg[6] = %d\t\t At address &iArray_vtg[6] : %p\n", iArray_vtg[6], &iArray_vtg[6]);
    printf("iArray_vtg[7] = %d\t\t At address &iArray_vtg[7] : %p\n", iArray_vtg[7], &iArray_vtg[7]);
    printf("iArray_vtg[8] = %d\t\t At address &iArray_vtg[8] : %p\n", iArray_vtg[8], &iArray_vtg[8]);
    printf("iArray_vtg[9] = %d\t\t At address &iArray_vtg[9] : %p\n", iArray_vtg[9], &iArray_vtg[9]);

    // Assigning base address of integer array 'iArray_vtg' to integer pointer 'ptr_iArray_vtg'
    // Name of any array is its own base address
    ptr_iArray_vtg = iArray_vtg; // Same as ... ptr_iArray_vtg = &iArray_vtg[0]

    // ###### Using pointer as pointer i.e : Value of xth element of iArray : *(ptr_iArray + x) and address of xth element of iArray : (ptr_iArray + x)
    printf("\n\n");
    printf("*** Using pointer as pointer i.e : Value of xth element of iArray : *(ptr_iArray_vtg + x) and address of xth element of iArray : (ptr_iArray_vtg + x) ***\n\n");
    printf("Integer array elements and their addresses :\n\n");
    printf("*(ptr_iArray_vtg + 0) = %d\t\t At address (ptr_iArray_vtg + 0) : %p\n", *(ptr_iArray_vtg + 0), (ptr_iArray_vtg + 0));
    printf("*(ptr_iArray_vtg + 1) = %d\t\t At address (ptr_iArray_vtg + 1) : %p\n", *(ptr_iArray_vtg + 1), (ptr_iArray_vtg + 1));
    printf("*(ptr_iArray_vtg + 2) = %d\t\t At address (ptr_iArray_vtg + 2) : %p\n", *(ptr_iArray_vtg + 2), (ptr_iArray_vtg + 2));
    printf("*(ptr_iArray_vtg + 3) = %d\t\t At address (ptr_iArray_vtg + 3) : %p\n", *(ptr_iArray_vtg + 3), (ptr_iArray_vtg + 3));
    printf("*(ptr_iArray_vtg + 4) = %d\t\t At address (ptr_iArray_vtg + 4) : %p\n", *(ptr_iArray_vtg + 4), (ptr_iArray_vtg + 4));
    printf("*(ptr_iArray_vtg + 5) = %d\t\t At address (ptr_iArray_vtg + 5) : %p\n", *(ptr_iArray_vtg + 5), (ptr_iArray_vtg + 5));
    printf("*(ptr_iArray_vtg + 6) = %d\t\t At address (ptr_iArray_vtg + 6) : %p\n", *(ptr_iArray_vtg + 6), (ptr_iArray_vtg + 6));
    printf("*(ptr_iArray_vtg + 7) = %d\t\t At address (ptr_iArray_vtg + 7) : %p\n", *(ptr_iArray_vtg + 7), (ptr_iArray_vtg + 7));
    printf("*(ptr_iArray_vtg + 8) = %d\t\t At address (ptr_iArray_vtg + 8) : %p\n", *(ptr_iArray_vtg + 8), (ptr_iArray_vtg + 8));
    printf("*(ptr_iArray_vtg + 9) = %d\t\t At address (ptr_iArray_vtg + 9) : %p\n", *(ptr_iArray_vtg + 9), (ptr_iArray_vtg + 9));

    return (0);
}