#include <stdio.h>

// *** GLOBAL SCOPE ***
int main(void)
{
    // *** LOCAL SCOPE OF main() begins ***

    // variable declarations
    // 'a' is a local variable. It is local to main() only
    int a_vtg = 5;

    // function prototype
    void change_count(void);

    // code
    printf("\n");
    printf("A = %d\n\n", a_vtg);

    // local_count_vtg is initialized to 0
    // local_count_vtg = local_count_vtg + 1 = 0 + 1 = 1
    change_count();

    // Since, 'local_count_vtg' is a local static variable of change_count(), it will retain its value from previous call to change_count()
    // So local_count_vtg is 1
    // local_count_vtg = local_count_vtg + 1 = 1 + 1 = 2
    change_count();

    // Since, 'local_count_vtg' is a local static variable of change_count(), it will retain its value from previous call to change_count()
    // So local_count_vtg is 2
    // local_count_vtg = local_count_vtg + 1 = 2 + 1 = 3
    change_count();

    return (0);

    // *** LOCAL SCOPE OF main() ends ***
}

// *** GLOBAL SCOPE ***
void change_count(void)
{
    // *** LOCAL SCOPE OF change_count() begins ***

    // variable declarations
    // 'local_count_vtg' is a local static variable. it is local to change_count() only
    // it will retain its value between calls to change_count()
    static int local_count_vtg = 0;

    // code
    local_count_vtg = local_count_vtg + 1;
    printf("Local count = %d\n", local_count_vtg);

    // *** LOCAL SCOPE OF change_count() ends ***
}

// *** GLOBAL SCOPE ***