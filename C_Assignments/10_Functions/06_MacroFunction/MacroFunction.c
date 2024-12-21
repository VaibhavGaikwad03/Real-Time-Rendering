#include <stdio.h>

#define MAX_NUMBER(a, b) ((a > b) ? a : b)

int main(int argc, char *argv[], char *envp[])
{
    // variable declarations
    int i_num_01_vtg;
    int i_num_02_vtg;
    int i_result_vtg;

    float f_num_01_vtg;
    float f_num_02_vtg;
    float f_result_vtg;

    // code
    // *** COMPARING INTEGER VALUES ***
    printf("\n\n");
    printf("Enter an integer number: ");
    scanf("%d", &i_num_01_vtg);

    printf("\n\n");
    printf("Enter another integer number: ");
    scanf("%d", &i_num_02_vtg);

    i_result_vtg = MAX_NUMBER(i_num_01_vtg, i_num_02_vtg);
    printf("\n\n");
    printf("Result of macro function MAX_NUMBER() = %d\n", i_result_vtg);
    printf("\n\n");

    // *** COMPARING FLOATING-POINT VALUES ***
    printf("\n\n");
    printf("Enter a floating point number: ");
    scanf("%f", &f_num_01_vtg);

    printf("\n\n");
    printf("Enter another floating point number: ");
    scanf("%f", &f_num_02_vtg);

    f_result_vtg = MAX_NUMBER(f_num_01_vtg, f_num_02_vtg);
    printf("\n\n");
    printf("Result of macro function MAX_NUMBER() = %f\n", f_result_vtg);
    printf("\n\n");

    return (0);
}