#include <stdio.h>

#define MAX_NAME_LENGTH 100

struct Employee
{
    char name[MAX_NAME_LENGTH];
    unsigned int age;
    char gender;
    double salary;
};

struct MyData
{
    int i;
    float f;
    double d;
    char c;
};

int main(void)
{
    //   Typedefs
    typedef struct Employee MY_EMPLOYEE_TYPE;
    typedef struct MyData MY_DATA_TYPE;

    //   variable   declarations
    struct Employee emp_vtg = {"Funny", 25, 'M', 10000.00};
    MY_EMPLOYEE_TYPE emp_typedef_vtg = {"Bunny", 23, 'F', 20400.00};

    struct MyData md_vtg = {30, 11.45f, 26.122017, 'X'};
    MY_DATA_TYPE md_typedef_vtg;

    //   code
    md_typedef_vtg.i = 9;
    md_typedef_vtg.f = 1.5f;
    md_typedef_vtg.d = 8.041997;
    md_typedef_vtg.c = 'P';

    printf("\n\n");
    printf("struct Employee : \n\n");
    printf("emp_vtg.name = %s\n", emp_vtg.name);
    printf("emp_vtg.age = %d\n", emp_vtg.age);
    printf("emp_vtg.gender = %c\n", emp_vtg.gender);
    printf("emp_vtg.salary = %lf\n", emp_vtg.salary);

    printf("\n\n");
    printf("MY_EMPLOYEE_TYPE : \n\n");
    printf("emp_typedef_vtg.name = %s\n", emp_typedef_vtg.name);
    printf("emp_typedef_vtg.age = %d\n", emp_typedef_vtg.age);
    printf("emp_typedef_vtg.gender = %c\n", emp_typedef_vtg.gender);
    printf("emp_typedef_vtg.salary = %lf\n", emp_typedef_vtg.salary);

    printf("\n\n");
    printf("struct MyData : \n\n");
    printf("md_vtg.i = %d\n", md_vtg.i);
    printf("md_vtg.f = %f\n", md_vtg.f);
    printf("md_vtg.d = %lf\n", md_vtg.d);
    printf("md_vtg.c = %c\n", md_vtg.c);

    printf("\n\n");
    printf("MY_DATA_TYPE : \n\n");
    printf("md_typedef_vtg.i = %d\n", md_typedef_vtg.i);
    printf("md_typedef_vtg.f = %f\n", md_typedef_vtg.f);
    printf("md_typedef_vtg.d = %lf\n", md_typedef_vtg.d);
    printf("md_typedef_vtg.c = %c\n", md_typedef_vtg.c);

    printf("\n\n");

    return (0);
}