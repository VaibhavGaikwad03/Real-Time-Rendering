#include <stdio.h>

#define NUM_ROWS 5
#define NUM_COLUMNS 3

int main(void) // variable declarations
{
    int iArray_vtg[NUM_ROWS][NUM_COLUMNS];
    int i_vtg, j_vtg;

    // code
    // *** NAME OF AN ARRAY ITSELF IS ITS BASE ADDRESS ***
    // *** HENCE, ’iArray' IS BASE ADDRESS OF 2D INTEGER ARRAY iArray[][]
    // iArray[5][3] => OF THESE 5 ROWS
    // iArray[0] => IS
    // iArray[1] => IS
    // iArray[4] => IS
    // (iArray[0] + 0) (iArray[0][0])
    // (iArray[0] + 1) (iArray[0][1])
    // (iArray[0] + 2) (iArray[0][2])
    // (iArray[1] + 0) (iArray[1][0])
    // (iArray[1] + 1) (iArray[1][1])
    // (iArray[1] + 2) (iArray[1][2])
    // iArray ISA 2D ARRAY HAVING 5 ROWS AND 3 COLUMNS. EACH ISA 1D INTGER ARRAY OF 3 INTEGERS ***
    // THE OTH ROW ... HENCE, IS THE BASE ADDRESS OF ROW0
    // THE IST ROW ... HENCE, IS THE BASE ADDRESS OF ROW 1
    // THE 4TH ROW ... HENCE, IS THE BASE ADDRESS OF ROW4
    // => ADDRESS OF 0th INTEGER FROM BASE ADDRESS OF 0th ROW
    // => ADDRESS OF 1ST INTEGER FROM BASE ADDRESS OF 0th ROW
    // => ADDRESS OF 2ND INTEGER FROM BASE ADDRESS OF 0th ROW
    // => ADDRESS OF 0th INTEGER FROM BASE ADDRESS OF lST ROW
    // => ADDRESS OF IST INTEGER FROM BASE ADDRESS OF 1ST ROW
    // => ADDRESS OF 2ND INTEGER FROM BASE ADDRESS OF IST ROW
    // iArray[0], iArray[1] ... ARE 1D INTEGR ARRAYS AND HENCE CAN BE TREATED AS ID INTEGER ARRAYS USING POINTERS ...
    // ’iArray’ IS THE NAME AND BASE ADDRESS OF 2D INTEGER ARRAY ***
    // (*(iArray + 0) + 0) = (iArray[0] + 0) = ADDRESS OF OTH ELEMENT FROM BASED ADDRESS OF OTH ROW = (iArray[0] + 0) = (iArray[0][0])
    // (*(iArray + 0) + 1) = (iArray[0] + 1) = ADDRESS OF 1ST ELEMENT FROM BASED ADDRESS OF OTH ROW = (iArray[0] + 1) = (iArray[0][1])
    // (*(iArray + 0) + 2) = (iArray[0] + 2) = ADDRESS OF 2ND ELEMENT FROM BASED ADDRESS OF OTH ROW = (iArray[0] + 2) = (iArray[0][2])
    // (*(iArray + 1)+ 0) = (iArray[1] + 0) = ADDRESS OF OTH ELEMENT FROM BASED ADDRESS OF lST ROW = (iArray[1] + 0) = (iArray[1][0])
    // (*(iArray + 1)+ 1) = (iArray[1] + 1) = ADDRESS OF 1ST ELEMENT FROM BASED ADDRESS OF lST ROW = (iArray[1] + 1) = (iArray[1][1])
    // (*(iArray + 1)+ 2) = (iArray[1] + 2) = ADDRESS OF 2ND ELEMENT FROM BASED ADDRESS OF lST ROW = (iArray[1] + 2) = (iArray[1][2])

    for (i_vtg = 0; i_vtg < NUM_ROWS; i_vtg++)
        for (j_vtg = 0; j_vtg < NUM_COLUMNS; j_vtg++)
            *(*(iArray_vtg + i_vtg) + j_vtg) = (i_vtg + 1) * (j_vtg + 1); // 'iArray[i]' Can Be v Treated As 1D Array Using Pointers ...

    printf("\n\n");
    printf("2D Integer Array Elements Along With Addresses : \n\n");

    for (i_vtg = 0; i_vtg < NUM_ROWS; i_vtg++)
    {
        for (j_vtg = 0; j_vtg < NUM_COLUMNS; j_vtg++)
            printf("*(*(iArray_vtg + %d) + %d)= %d \t \t At Address (*(iArray_vtg + %d) + %d) : %p\n", i_vtg, j_vtg, *(*(iArray_vtg + i_vtg) + j_vtg), i_vtg, j_vtg, (*(iArray_vtg + i_vtg) + j_vtg));
        printf("\n\n");
    }

    return (0);
}