#include <stdio.h>

int main(void)
{
    // variable declarations
    int iArray_vtg[] = {12, 24, 36, 48, 60, 72, 84, 96, 108, 120};
    float fArray_vtg[] = {9.8f, 8.7f, 7.6f, 6.5f, 5.4f};
    double dArray_vtg[] = {1.222222, 2.333333, 3.444444};
    char cArray_vtg[] = {'A', 'S', 'T', 'R', '0', 'M', 'E', 'D', 'I', 'C', '0', 'M', 'P', '\0'};

    // code
    printf("\n\n");
    printf("Integer array elements and the addresses they occupy are as follows : \n\n");
    printf("iArray_vtg[0] = %d \t At address : %p\n", *(iArray_vtg + 0), (iArray_vtg + 0));
    printf("iArray_vtg[1] = %d \t At address : %p\n", *(iArray_vtg + 1), (iArray_vtg + 1));
    printf("iArray_vtg[2] = %d \t At address : %p\n", *(iArray_vtg + 2), (iArray_vtg + 2));
    printf("iArray_vtg[3] = %d \t At address : %p\n", *(iArray_vtg + 3), (iArray_vtg + 3));
    printf("iArray_vtg[4] = %d \t At address : %p\n", *(iArray_vtg + 4), (iArray_vtg + 4));
    printf("iArray_vtg[5] = %d \t At address : %p\n", *(iArray_vtg + 5), (iArray_vtg + 5));
    printf("iArray_vtg[6] = %d \t At address : %p\n", *(iArray_vtg + 6), (iArray_vtg + 6));
    printf("iArray_vtg[7] = %d \t At address : %p\n", *(iArray_vtg + 7), (iArray_vtg + 7));
    printf("iArray_vtg[8] = %d \t At address : %p\n", *(iArray_vtg + 8), (iArray_vtg + 8));
    printf("iArray_vtg[9] = %d \t At address : %p\n", *(iArray_vtg + 9), (iArray_vtg + 9));

    printf("\n\n");
    printf("Float array elements and the addresses they occupy are as follows : \n\n");
    printf("fArray_vtg[0] = %f \t At address : %p\n", *(fArray_vtg + 0), (fArray_vtg + 0));
    printf("fArray_vtg[1] = %f \t At address : %p\n", *(fArray_vtg + 1), (fArray_vtg + 1));
    printf("fArray_vtg[2] = %f \t At address : %p\n", *(fArray_vtg + 2), (fArray_vtg + 2));
    printf("fArray_vtg[3] = %f \t At address : %p\n", *(fArray_vtg + 3), (fArray_vtg + 3));
    printf("fArray_vtg[4] = %f \t At address : %p\n", *(fArray_vtg + 4), (fArray_vtg + 4));

    printf("\n\n");
    printf("Double array elements and the addresses they occupy are as follows : \n\n");
    printf("dArray_vtg[0] = %lf \t At address : %p\n", *(dArray_vtg + 0), (dArray_vtg + 0));
    printf("dArray_vtg[1] = %lf \t At address : %p\n", *(dArray_vtg + 1), (dArray_vtg + 1));
    printf("dArray_vtg[2] = %lf \t At address : %p\n", *(dArray_vtg + 2), (dArray_vtg + 2));

    printf("\n\n");
    printf("Character array elements and the addresses they occupy are as follows : \n\n");
    printf("cArray_vtg[0] = %c \t At address : %p\n", *(cArray_vtg + 0), (cArray_vtg + 0));
    printf("cArray_vtg[1] = %c \t At address : %p\n", *(cArray_vtg + 1), (cArray_vtg + 1));
    printf("cArray_vtg[2] = %c \t At address : %p\n", *(cArray_vtg + 2), (cArray_vtg + 2));
    printf("cArray_vtg[3] = %c \t At address : %p\n", *(cArray_vtg + 3), (cArray_vtg + 3));
    printf("cArray_vtg[4] = %c \t At address : %p\n", *(cArray_vtg + 4), (cArray_vtg + 4));
    printf("cArray_vtg[5] = %c \t At address : %p\n", *(cArray_vtg + 5), (cArray_vtg + 5));
    printf("cArray_vtg[6] = %c \t At address : %p\n", *(cArray_vtg + 6), (cArray_vtg + 6));
    printf("cArray_vtg[7] = %c \t At address : %p\n", *(cArray_vtg + 7), (cArray_vtg + 7));
    printf("cArray_vtg[8] = %c \t At address : %p\n", *(cArray_vtg + 8), (cArray_vtg + 8));
    printf("cArray_vtg[9] = %c \t At address : %p\n", *(cArray_vtg + 9), (cArray_vtg + 9));
    printf("cArray_vtg[10] = %c \t At address : %p\n", *(cArray_vtg + 10), (cArray_vtg + 10));
    printf("cArray_vtg[11] = %c \t At address : %p\n", *(cArray_vtg + 11), (cArray_vtg + 11));
    printf("cArray_vtg[12] = %c \t At address : %p\n", *(cArray_vtg + 12), (cArray_vtg + 12));
    printf("cArray_vtg[13] = %c \t At address : %p\n", *(cArray_vtg + 13), (cArray_vtg + 13));

    return (0);
}