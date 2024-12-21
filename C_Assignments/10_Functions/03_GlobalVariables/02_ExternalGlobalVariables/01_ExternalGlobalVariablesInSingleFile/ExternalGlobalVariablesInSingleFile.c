#include <stdio.h>

//***GLOBAL SCOPE***

int main(void)
{
    // function prototypes
    void change_count(void);

    // variable declarations
    extern int global_count_vtg;

    // code
    printf("\n");
    printf("Value of global_count_vtg before change_count() %d\n", global_count_vtg);
    change_count();
    printf("Value of global_count_vtg after change_count() %d\n", global_count_vtg);
    printf("\n");
    return (0);
}

//***GLOBAL SCOPE***
// global_count_vtg is a global variable.
// Since, it is declared before change_count(), it can be accessed and used as any ordinary global variable in change_count()
// Since, it is declared after main(), it must be first re-declared in main() as an external global variable by means of the 'extern' keyword and the type of the variable.
// Once this is done, it can be used as an ordinary global variable in main as well.
int global_count_vtg = 0;

void change_count(void)
{
    // code
    global_count_vtg = 5;
    printf("Value Of global_count_vtg in change_count() %d\n", global_count_vtg);
}