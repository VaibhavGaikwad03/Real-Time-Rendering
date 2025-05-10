#include <stdio.h>

#define NAME_LENGTH 100
#define MARITAL_STATUS 10

struct Employee
{
    char name[NAME_LENGTH];
    int age;
    float salary;
    char sex;
    char marital_status[MARITAL_STATUS];
};

int main(void)
{
    // variable declarations
    struct Employee EmployeeRecord_vtg[5]; // An array of 5 structs - Each being type 'struct Employee'
    char employee_rajesh_vtg[] = "Rajesh";
    char employee_sameer_vtg[] = "Sameer";
    char employee_kalyani_vtg[] = "Kalyani";
    char employee_sonali_vtg[] = "Sonali";
    char employee_shantanu_vtg[] = "Shantanu";

    int i;

    // HARD - CODED INITIALIZATION OF ARRAY OF 'struct Employee' * *****

    // ****** EMPLOYEE 1 ******
    strcpy(EmployeeRecord_vtg[0].name, employee_rajesh_vtg);
    EmployeeRecord_vtg[0].age = 30;
    EmployeeRecord_vtg[0].sex = 'M';
    EmployeeRecord_vtg[0].salary = 50000.0f;
    strcpy(EmployeeRecord_vtg[0].marital_status, "Unmarried");

    // ****** EMPLOYEE 2 ******
    strcpy(EmployeeRecord_vtg[1].name, employee_sameer_vtg);
    EmployeeRecord_vtg[1].age = 32;
    EmployeeRecord_vtg[1].sex = 'M';
    EmployeeRecord_vtg[1].salary = 60000.0f;
    strcpy(EmployeeRecord_vtg[1].marital_status, "Married");

    // ****** EMPLOYEE 3 ******
    strcpy(EmployeeRecord_vtg[2].name, employee_kalyani_vtg);
    EmployeeRecord_vtg[2].age = 29;
    EmployeeRecord_vtg[2].sex = 'F';
    EmployeeRecord_vtg[2].salary = 62000.0f;
    strcpy(EmployeeRecord_vtg[2].marital_status, "Unmarried");

    // ****** EMPLOYEE 4 ******
    strcpy(EmployeeRecord_vtg[3].name, employee_sonali_vtg);
    EmployeeRecord_vtg[3].age = 33;
    EmployeeRecord_vtg[3].sex = 'F';
    EmployeeRecord_vtg[3].salary = 50000.0f;
    strcpy(EmployeeRecord_vtg[3].marital_status, "Married");

    // ****** EMPLOYEE 5 ******
    strcpy(EmployeeRecord_vtg[4].name, employee_shantanu_vtg);
    EmployeeRecord_vtg[4].age = 35;
    EmployeeRecord_vtg[4].sex = 'M';
    EmployeeRecord_vtg[4].salary = 55000.0f;
    strcpy(EmployeeRecord_vtg[4].marital_status, "Married");

    // *** DISPLAY ***
    printf("\n\n");
    printf("****** DISPLAYING EMPLOYEE RECORDS ******\n\n");
    for (i = 0; i < 5; i++)
    {
        printf("****** EMPLOYEE NUMBER %d ******\n\n", (i + 1));
        printf("Name   :   %s\n", EmployeeRecord_vtg[i].name);
        printf("Age   :   %d   years\n", EmployeeRecord_vtg[i].age);

        if (EmployeeRecord_vtg[i].sex == 'M' || EmployeeRecord_vtg[i].sex == 'm')
            printf("Sex   :   Male\n");
        else
            printf("Sex   :   Female\n");

        printf("Salary   :   Rs.   %f\n", EmployeeRecord_vtg[i].salary);
        printf("Marital Status   :   %s\n", EmployeeRecord_vtg[i].marital_status);
        printf("\n\n");
    }
    return (0);
}