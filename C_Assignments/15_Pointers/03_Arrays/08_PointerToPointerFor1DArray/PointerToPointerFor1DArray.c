#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    void MyAlloc(int **ptr, unsigned int numberOfElements);

    // variable declarations
    int *piArray_vtg = NULL;
    unsigned int num_elements_vtg;
    int i_vtg;

    // code
    printf("\n\n");
    printf("How many elements you want in integer array?\n\n");
    scanf("%u", &num_elements_vtg);

    printf("\n\n");
    MyAlloc(&piArray_vtg, num_elements_vtg);

    printf("Enter %u elements to fill up your integer array: \n\n", num_elements_vtg);

    for (i_vtg = 0; i_vtg < num_elements_vtg; i_vtg++)
        scanf("%d", &piArray_vtg[i_vtg]);

    printf("\n\n");
    printf("The %u elements entered by you in the integer array: \n\n", num_elements_vtg);

    for (i_vtg = 0; i_vtg < num_elements_vtg; i_vtg++)
        printf("%u\n", piArray_vtg[i_vtg]);

    printf("\n\n");
    if (piArray_vtg)
    {
        free(piArray_vtg);
        piArray_vtg = NULL;
        printf("Memory allocated has now been successfully freed!!!\n\n");
    }

    return (0);
}

void MyAlloc(int **ptr, unsigned int numberOfElements)
{
    // code
    *ptr = (int *)malloc(numberOfElements * sizeof(int));

    if (*ptr == NULL)
    {
        printf("Could not allocate memory !!! Exiting...\n\n");
        exit(0);
    }

    printf("MyAlloc() has successfully allocated %llu bytes for integer array!!!\n\n", (numberOfElements * sizeof(int)));
}