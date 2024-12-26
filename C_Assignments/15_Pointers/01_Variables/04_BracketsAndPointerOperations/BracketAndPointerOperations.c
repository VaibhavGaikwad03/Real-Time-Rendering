#include <stdio.h>

int main(void)
{
    int num_vtg;
    int *ptr_vtg = NULL;
    int ans_vtg;

    num_vtg = 5;
    ptr_vtg = &num_vtg;

    printf("\n\n");
    printf("num_vtg = %d\n", num_vtg);
    printf("&num_vtg = %p\n", &num_vtg);
    printf("*(&num_vtg) = %d\n", *(&num_vtg));
    printf("ptr_vtg = %p\n", ptr_vtg);
    printf("*ptr_vtg = %d\n", *ptr_vtg);

    printf("\n\n");
    printf("Answer Of (ptr_vtg + 10) = %p\n", (ptr_vtg + 10));
    printf("Answer Of *(ptr_vtg + 10) = %d\n", *(ptr_vtg + 10));
    printf("Answer Of (*ptr_vtg + 10) = %d\n\n", (*ptr_vtg + 10));

    ++*ptr_vtg;
    printf("Answer Of ++*ptr_vtg : %d\n", *ptr_vtg);

    *ptr_vtg++;
    printf("Answer Of *ptr_vtg++ : %d\n", *ptr_vtg);

    ptr_vtg = &num_vtg;
    (*ptr_vtg)++;
    printf("Answer Of (*ptr_vtg)++ : %d\n\n", *ptr_vtg);

    return (0);
}