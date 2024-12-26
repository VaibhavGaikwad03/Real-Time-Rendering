#include <stdio.h>
#include <ctype.h>

#define NUM_EMPLOYEES 1 // Simply change this constant value to have as many number of Employee Records as you please ...

#define NAME_LENGTH 100
#define MARITAL_STATUS 10

struct Employee
{
    char name[NAME_LENGTH];
    int age;
    char sex;
    float salary;
    char marital_status;
};

int main(void)
{
    // Function prototype
    void MyGetString(char[], int);

    // Variable declarations
    struct Employee EmployeeRecord_vtg[NUM_EMPLOYEES]; // An array of <NUM_EMPLOYEES> structs - Each being type 'struct Employee'
    int i_vtg;

    // ****** USER INPUT INITIALIZATION OF ARRAY OF 'struct Employee' ******
    for (i_vtg = 0; i_vtg < NUM_EMPLOYEES; i_vtg++)
    {
        printf("\n\n\n\n");
        printf("********** Data entry for employee number %d **********\n", (i_vtg + 1));

        printf("\n\n");
        printf("Enter employee name: ");
        MyGetString(EmployeeRecord_vtg[i_vtg].name, NAME_LENGTH);

        printf("\n\n\n");
        printf("Enter employee's age (in years): ");
        scanf("%d", &EmployeeRecord_vtg[i_vtg].age);

        printf("\n\n");
        printf("Enter employee's sex (M/m for male, F/f for female): ");
        scanf(" %c", &EmployeeRecord_vtg[i_vtg].sex);
        EmployeeRecord_vtg[i_vtg].sex = toupper(EmployeeRecord_vtg[i_vtg].sex);

        printf("\n\n\n");
        printf("Enter employee's salary (in Indian rupees): ");
        scanf("%f", &EmployeeRecord_vtg[i_vtg].salary);

        printf("\n\n");
        printf("Is the employee married? (Y/y for yes, N/n for no): ");
        scanf(" %c", &EmployeeRecord_vtg[i_vtg].marital_status);
        EmployeeRecord_vtg[i_vtg].marital_status = toupper(EmployeeRecord_vtg[i_vtg].marital_status);
    }

    // *** DISPLAY ***
    printf("\n\n\n\n");
    printf("********** Displaying employee records **********\n\n");
    for (i_vtg = 0; i_vtg < NUM_EMPLOYEES; i_vtg++)
    {
        printf("*********** Employee number %d **********\n\n", (i_vtg + 1));
        printf("Name: %s\n", EmployeeRecord_vtg[i_vtg].name);
        printf("Age: %d years\n", EmployeeRecord_vtg[i_vtg].age);

        if (EmployeeRecord_vtg[i_vtg].sex == 'M')
            printf("Sex: Male\n");
        else if (EmployeeRecord_vtg[i_vtg].sex == 'F')
            printf("Sex: Female\n");
        else
            printf("Sex: Invalid data entered\n");

        printf("Salary: Rs. %.2f\n", EmployeeRecord_vtg[i_vtg].salary);

        if (EmployeeRecord_vtg[i_vtg].marital_status == 'Y')
            printf("Marital status: Married\n");
        else if (EmployeeRecord_vtg[i_vtg].marital_status == 'N')
            printf("Marital status: Unmarried\n");
        else
            printf("Marital status: Invalid data entered\n");

        printf("\n\n");
    }

    return 0;
}

// *** SIMPLE RUDIMENTARY IMPLEMENTATION OF gets_s() ***
// *** IMPLEMENTED DUE TO DIFFERENT BEHAVIOR OF gets_s() / fgets() / fscanf() ON DIFFERENT PLATFORMS ***
// *** BACKSPACE / CHARACTER DELETION AND ARROW KEY CURSOR MOVEMENT NOT IMPLEMENTED ***
void MyGetString(char str_vtg[], int str_size_vtg)
{
    // Variable declarations
    int i_vtg;
    char ch_vtg = '\0';

    // Code
    i_vtg = 0;
    do
    {
        ch_vtg = getchar(); // Changed `getch` to `getchar` for portability
        if (ch_vtg == '\n') // Prevent newline from being added
            break;
        str_vtg[i_vtg] = ch_vtg;
        printf("%c", str_vtg[i_vtg]);
        i_vtg++;
    } while ((i_vtg < str_size_vtg));

    if (i_vtg == str_size_vtg)
        str_vtg[i_vtg - 1] = '\0';
    else
        str_vtg[i_vtg] = '\0';
}