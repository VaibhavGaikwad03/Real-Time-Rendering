#include <stdio.h>

struct Employee
{
    // Structure definition for Employee
    char name_vtg[100];
    int age_vtg;
    float salary_vtg;
    char sex_vtg;
    char marital_status_vtg;
};

int main(void) // code
{
    printf("\n\n");
    printf("SIZES OF DATA TYPES AND POINTERS TO THOSE RESPECTIVE DATA TYPES ARE : \n\n");

    printf("Size of (int) : %d \t \t \t Size of pointer to int (int*) : %d\n\n", sizeof(int), sizeof(int *));

    printf("Size of (float) : %d \t \t \t Size of pointer to float (float*) : %d\n\n", sizeof(float), sizeof(float *));

    printf("Size of (double) : %d \t \t \t Size of pointer to double (double*) : %d\n\n", sizeof(double), sizeof(double *));

    printf("Size of (char) : %d \t \t \t Size of pointer to char (char*) : %d\n\n", sizeof(char), sizeof(char *));

    printf("Size of (struct Employee) : %d \t \t Size of pointer to struct Employee (struct Employee*) : %d\n\n", sizeof(struct Employee), sizeof(struct Employee *));

    return (0);
}