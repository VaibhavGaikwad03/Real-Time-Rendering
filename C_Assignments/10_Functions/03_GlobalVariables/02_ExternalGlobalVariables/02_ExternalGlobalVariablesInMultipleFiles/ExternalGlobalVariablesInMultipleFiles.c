#include <stdio.h>

// *** GLOBAL SCOPE ***
int global_count_vtg = 0;

int main(void)
{
    // function prototypes
    void change_count(void);
    void change_count_one(void); // function defines in File_01.c
    void change_count_two(void); // function defines in File_02.c

    // code
    printf("\n");

    change_count();
    change_count_one();
    change_count_two();

    return (0);
}

void change_count()
{
    // code
    global_count_vtg = global_count_vtg + 1;
    printf("Global count = %d\n", global_count_vtg);
}