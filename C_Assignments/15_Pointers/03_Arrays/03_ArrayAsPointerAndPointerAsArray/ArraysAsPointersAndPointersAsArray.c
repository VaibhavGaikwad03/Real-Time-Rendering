#include <stdio.h>

int main(void)
// variable declarations
{
    int iArray_vtg[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100}; // Integer Array
    int *ptr_iArray_vtg = NULL;                                   // Integer Pointer

    // code
    //    ######   USING   ARRAY   NAME   AS A   POINTER   i.e   :   Value   Of   xth   Element   Of  iArray_vtg   :   *(iArray_vtg   +   x)   AND   Address   Of   xth   Element   Of   iArray_vtg   :   (iArray_vtg   +   x)
    printf("\n\n");
    printf("*** Using array name as a pointer i.e : Value of xth element of iArray_vtg : *(iArray_vtg + x) and address of xth element of iArray_vtg : (iArray_vtg + x) ***\n\n");
    printf("Integer array elements and their addresses :   \n\n");
    printf("*(iArray_vtg + 0) = %d   \t At address(iArray_vtg + 0) : %p\n", *(iArray_vtg + 0), (iArray_vtg + 0));
    printf("*(iArray_vtg + 1) = %d   \t At address(iArray_vtg + 1) : %p\n", *(iArray_vtg + 1), (iArray_vtg + 1));
    printf("*(iArray_vtg + 2) = %d   \t At address(iArray_vtg + 2) : %p\n", *(iArray_vtg + 2), (iArray_vtg + 2));
    printf("*(iArray_vtg + 3) = %d   \t At address(iArray_vtg + 3) : %p\n", *(iArray_vtg + 3), (iArray_vtg + 3));
    printf("*(iArray_vtg + 4) = %d   \t At address(iArray_vtg + 4) : %p\n", *(iArray_vtg + 4), (iArray_vtg + 4));
    printf("*(iArray_vtg + 5) = %d   \t At address(iArray_vtg + 5) : %p\n", *(iArray_vtg + 5), (iArray_vtg + 5));
    printf("*(iArray_vtg + 6) = %d   \t At address(iArray_vtg + 6) : %p\n", *(iArray_vtg + 6), (iArray_vtg + 6));
    printf("*(iArray_vtg + 7) = %d   \t At address(iArray_vtg + 7) : %p\n", *(iArray_vtg + 7), (iArray_vtg + 7));
    printf("*(iArray_vtg + 8) = %d   \t At address(iArray_vtg + 8) : %p\n", *(iArray_vtg + 8), (iArray_vtg + 8));
    printf("*(iArray_vtg + 9) = %d   \t At address(iArray_vtg + 9) : %p\n", *(iArray_vtg + 9), (iArray_vtg + 9));

    //   ASSIGNING   BASE   ADDRESS   OF   INTEGER   ARRAY   'iArray_vtg'   TO   INTEGER   POINTER  'ptr_iArray_vtg'
    //   NAME   OF   ANY   ARRAY   IS   ITS   OWN   BASE   ADDRESS
    ptr_iArray_vtg = iArray_vtg; // SAME   AS   ...   ptr_iArray_vtg   = &iArray_vtg[0]

    printf("\n\n");
    printf("*** Using pointer as array name i.e : Value of xth element of ptr_iArray_vtg[x] and address of xth element of iArray_vtg : &ptr_iArray_vtg[x] ***\n\n");
    printf("Integer array elements and their addresses : \n\n");
    printf("ptr_iArray_vtg[0] = %d   \t At address &ptr_iArray_vtg[0] : %p\n", ptr_iArray_vtg[0], &ptr_iArray_vtg[0]);
    printf("ptr_iArray_vtg[1] = %d   \t At address &ptr_iArray_vtg[1] : %p\n", ptr_iArray_vtg[1], &ptr_iArray_vtg[1]);
    printf("ptr_iArray_vtg[2] = %d   \t At address &ptr_iArray_vtg[2] : %p\n", ptr_iArray_vtg[2], &ptr_iArray_vtg[2]);
    printf("ptr_iArray_vtg[3] = %d   \t At address &ptr_iArray_vtg[3] : %p\n", ptr_iArray_vtg[3], &ptr_iArray_vtg[3]);
    printf("ptr_iArray_vtg[4] = %d   \t At address &ptr_iArray_vtg[4] : %p\n", ptr_iArray_vtg[4], &ptr_iArray_vtg[4]);
    printf("ptr_iArray_vtg[5] = %d   \t At address &ptr_iArray_vtg[5] : %p\n", ptr_iArray_vtg[5], &ptr_iArray_vtg[5]);
    printf("ptr_iArray_vtg[6] = %d   \t At address &ptr_iArray_vtg[6] : %p\n", ptr_iArray_vtg[6], &ptr_iArray_vtg[6]);
    printf("ptr_iArray_vtg[7] = %d   \t At address &ptr_iArray_vtg[7] : %p\n", ptr_iArray_vtg[7], &ptr_iArray_vtg[7]);
    printf("ptr_iArray_vtg[8] = %d   \t At address &ptr_iArray_vtg[8] : %p\n", ptr_iArray_vtg[8], &ptr_iArray_vtg[8]);
    printf("ptr_iArray_vtg[9] = %d   \t At address &ptr_iArray_vtg[9] : %p\n", ptr_iArray_vtg[9], &ptr_iArray_vtg[9]);
    
    return (0);
}