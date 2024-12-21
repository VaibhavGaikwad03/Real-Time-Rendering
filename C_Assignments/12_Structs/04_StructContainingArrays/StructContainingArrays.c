#include <stdio.h>
#include <string.h> // Added for strcpy function

#define INT_ARRAY_SIZE 12
#define FLOAT_ARRAY_SIZE 5
#define CHAR_ARRAY_SIZE 26

#define NUM_STRINGS 10
#define MAX_CHARACTERS_PER_STRING 20

#define ALPHABET_BEGINNING 65 //   'A'

struct MyDataOne_vtg
{
    int iArray_vtg[INT_ARRAY_SIZE];
    float fArray_vtg[FLOAT_ARRAY_SIZE];
};

struct MyDataTwo_vtg
{
    char cArray_vtg[CHAR_ARRAY_SIZE];
    char strArray_vtg[NUM_STRINGS][MAX_CHARACTERS_PER_STRING];
};

int main(void)
{
    // variable declarations
    struct MyDataOne_vtg data_one_vtg;
    struct MyDataTwo_vtg data_two_vtg;
    int i_vtg;

    //   ***   PIECE-MEAL   ASSIGNMENT   (HARD-CODED)   ***
    data_one_vtg.fArray_vtg[0] = 0.1f;
    data_one_vtg.fArray_vtg[1] = 1.2f;
    data_one_vtg.fArray_vtg[2] = 2.3f;
    data_one_vtg.fArray_vtg[3] = 3.4f;
    data_one_vtg.fArray_vtg[4] = 4.5f;

    //   ***   LOOP   ASSIGNMENT   (USER   INPUT)   ***
    printf("\n\n");
    printf("Enter %d Integers:   \n\n", INT_ARRAY_SIZE);
    for (i_vtg = 0; i_vtg < INT_ARRAY_SIZE; i_vtg++)
        scanf("%d", &data_one_vtg.iArray_vtg[i_vtg]);

    //   ***   LOOP   ASSIGNMENT   (HARD-CODED)   ***
    for (i_vtg = 0; i_vtg < CHAR_ARRAY_SIZE; i_vtg++)
        data_two_vtg.cArray_vtg[i_vtg] = (char)(i_vtg + ALPHABET_BEGINNING);

    //   ***   PIECE-MEAL   ASSIGNMENT   (HARD-CODED)   ***
    strcpy(data_two_vtg.strArray_vtg[0], "Welcome !!!");
    strcpy(data_two_vtg.strArray_vtg[1], "This");
    strcpy(data_two_vtg.strArray_vtg[2], "Is");
    strcpy(data_two_vtg.strArray_vtg[3], "ASTROMEDICOMP'S");
    strcpy(data_two_vtg.strArray_vtg[4], "Real");
    strcpy(data_two_vtg.strArray_vtg[5], "Time");
    strcpy(data_two_vtg.strArray_vtg[6], "Rendering");
    strcpy(data_two_vtg.strArray_vtg[7], "Batch");
    strcpy(data_two_vtg.strArray_vtg[8], "Of");
    strcpy(data_two_vtg.strArray_vtg[9], "2024-2025 !!!");

    //   ***   DISPLAYING   DATA   MEMBERS   OF   'struct   DataOne’   AND   THEIR   VALUES   ***
    printf("\n\n");
    printf("Members Of 'struct DataOne' Alongwith Their Assigned Values Are : \n\n");

    printf("\n\n");
    printf("Integer Array (data_one_vtg.iArray_vtg[])   :   \n\n");
    for (i_vtg = 0; i_vtg < INT_ARRAY_SIZE; i_vtg++)
        printf("data_one_vtg.iArray_vtg[%d] = %d\n", i_vtg, data_one_vtg.iArray_vtg[i_vtg]);

    printf("\n\n");
    printf("Floating-Point Array (data_one_vtg.fArray_vtg[]): \n\n");
    for (i_vtg = 0; i_vtg < FLOAT_ARRAY_SIZE; i_vtg++)
        printf("data_one_vtg.fArray_vtg[%d] = %f\n", i_vtg, data_one_vtg.fArray_vtg[i_vtg]);

    //   ***   DISPLAYING   DATA   MEMBERS   OF   'struct   DataTwo'   AND   THEIR   VALUES   ***
    printf("\n\n");
    printf("Members Of 'struct DataTwo' Alongwith Their Assigned Values Are: \n\n");

    printf("\n\n");
    printf("Character Array (data_two_vtg.cArray_vtg[]): \n\n");
    for (i_vtg = 0; i_vtg < CHAR_ARRAY_SIZE; i_vtg++)
        printf("data_two_vtg.cArray_vtg[%d] = %c\n", i_vtg, data_two_vtg.cArray_vtg[i_vtg]);

    ("\n\n");
    printf("String Array (data_two_vtg.strArray_vtg[])   :   \n\n");
    for (i_vtg = 0; i_vtg < NUM_STRINGS; i_vtg++)
        printf("%s ", data_two_vtg.strArray_vtg[i_vtg]);

    printf("\n\n");
    
    return (0);
}