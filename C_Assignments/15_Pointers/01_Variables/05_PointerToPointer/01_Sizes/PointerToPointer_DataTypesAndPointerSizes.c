#include <stdio.h>

struct Employee
{
    char name[100];
    int age;
    float salary;
    char sex;
    char marital_status;
};

int main(void) // code
{
    printf("\n\n");
    printf("SIZES OF DATA TYPES AND POINTERS TO THOSE RESPECTIVE DATA TYPES ARE : \n\n");
    
    printf("Size of (int) (int*) to int (int**) : %zd\t\t\tSize of pointer to int : %zd\t\t\tSize of pointer to pointer : %zd\n\n", sizeof(int), sizeof(int *), sizeof(int **));

    printf("Size of (float) : %zd\t\t\tSize of pointer to float (float*) : %zd\t\t\tSize of pointer to pointer to float (float**) : %zd\n\n", sizeof(float), sizeof(float *), sizeof(float **));

    printf("Size of (double) : %zd\t\t\tSize of pointer to double (double*) : %zd\t\t\tSize of pointer to pointer to double (double**) : %zd\n\n", sizeof(double), sizeof(double *), sizeof(double **));

    printf("Size of (char) : %zd\t\t\tSize of pointer to char (char*) : %zd\t\t\tSize of pointer to pointer to char (char**) : %zd\n\n", sizeof(char), sizeof(char *), sizeof(char **));
    
    printf("Size of (struct Employee) : %zd\t\tSize of pointer to struct Employee (struct Employee*) : %zd\t\t\tSize of pointer to pointer to struct Employee (struct Employee**) : %zd\n\n", sizeof(struct Employee), sizeof(struct Employee *), sizeof(struct Employee **));

    return (0);
}