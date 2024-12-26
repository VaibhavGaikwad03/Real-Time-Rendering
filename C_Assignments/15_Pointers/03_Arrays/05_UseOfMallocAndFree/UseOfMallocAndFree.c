#include <stdio.h>
#include <stdlib.h> //contains prototypes of malloc() and free()

int main(void)
{
    // variable declarations
    int *ptr_iArray_vtg = NULL; // It is good discipline to initialize any pointer with null address to prevent any garbage value getting into it, that way, it makes it easy to check for success or failure of memory allocation later on after malloc()...
    unsigned int intArrayLength_vtg = 0;
    int i_vtg;

    // code
    printf("\n\n");
    printf("Enter the number of elements you want in your integer array: ");
    scanf("%d", &intArrayLength_vtg);

    // ****** ALLOCATING AS MUCH MEMORY REQUIRED TO THE INTEGER ARRAY ******
    // ****** MEMORY REQUIRED FOR INTEGER ARRAY = SIZE IN BYTES OF ONE INTEGER * NUMBER OF INTEGERS TO BE STORED IN ARRAY ******
    //****** TO ALLOCATE SAID AMOUNT OF MEMORY, FUNCTION malloc() WILL BE USED ******
    //****** malloc() WILL ALLOCATE SAID AMOUNT OF MEMORY AND WILL RETURN THE INITIAL / STARTING / BASE ADDRESS OF THE ALLOCATED MEMORY, WHICH MUST BE CAPTURED IN A POINTER VARIABLE ******
    //****** USING THIS BASE ADDRESS, THE INTEGER ARRAY CAN BE ACCESSED AND USED ******

    ptr_iArray_vtg = (int *)malloc(sizeof(int) * intArrayLength_vtg);
    if (ptr_iArray_vtg == NULL) // If ptr_iArray_vtg is still null, even after call to malloc(), it means malloc() has failed to allocate memory and no address has been returned by malloc() in ptr_iArray_vtg...
    {
        printf("\n\n");
        printf("Memory allocation for integer array has failed! Exiting now...\n\n");
        exit(0);
    }
    else // If ptr_iArray_vtg is not null, it means it must contain a valid address which is returned by malloc(), hence, malloc() has succeeded in memory allocation...
    {
        printf("\n\n");
        printf("Memory allocation for integer array has succeeded!\n\n");
        printf("Memory addresses from %p to %p have been allocated to integer array!\n\n", ptr_iArray_vtg, (ptr_iArray_vtg + (intArrayLength_vtg - 1)));
    }

    printf("\n\n");
    printf("Enter %d elements for the integer array:\n\n", intArrayLength_vtg);
    for (i_vtg = 0; i_vtg < intArrayLength_vtg; i_vtg++)
        scanf("%d", (ptr_iArray_vtg + i_vtg));

    printf("\n\n");
    printf("The integer array entered by you, consisting of %d elements:\n", intArrayLength_vtg);
    for (i_vtg = 0; i_vtg < intArrayLength_vtg; i_vtg++)
    {
        printf("ptr_iArray_vtg[%d] = %d   \t \t At address &ptr_iArray_vtg[%d]: %p\n", i_vtg, ptr_iArray_vtg[i_vtg], i_vtg, &ptr_iArray_vtg[i_vtg]);
    }

    printf("\n\n");
    for (i_vtg = 0; i_vtg < intArrayLength_vtg; i_vtg++)
    {
        printf("*(ptr_iArray_vtg + %d) = %d \t \t At address (ptr_iArray_vtg + %d): %p\n", i_vtg, *(ptr_iArray_vtg + i_vtg), i_vtg, (ptr_iArray_vtg + i_vtg));
    }

    // ***** CHECKING IF MEMORY IS STILL ALLOCATED BY CHECKING VALIDITY OF BASED ADDRESS 'ptr_iArray_vtg' ******
    // ***** IF ADDRESS IS VALID, THAT IS IF 'ptr_iArray_vtg' EXISTS, THAT IS, IF IT IS NOT NULL, MEMORY IS STILL ALLOCATED ******
    //***** IN THAT CASE, THE ALLOCATED MEMORY MUST BE FREED ******
    //***** MEMORY IS ALLOCATED USING malloc() AND FREED USING free() ******
    //***** ONCE MEMORY IS FREED USING free(), THE BASE ADDRESS MUST BE CLEANED, THAT IS, IT MUST BE RE - INITILAIZED TO 'NULL' TO KEEP AWAY GARBAGE VALUES.THIS IS NOT COMPULSORY, BUT IT IS GOOD CODING DISCIPLINE ******

    if (ptr_iArray_vtg)
    {
        free(ptr_iArray_vtg);
        ptr_iArray_vtg = NULL;

        printf("\n\n");
        printf("Memory allocated for integer array has been successfully freed!\n\n");
    }

    return (0);
}