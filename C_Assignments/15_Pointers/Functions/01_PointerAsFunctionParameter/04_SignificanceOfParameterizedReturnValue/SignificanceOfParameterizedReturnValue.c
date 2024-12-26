#include <stdio.h>

enum
{
    NEGATIVE = -1,
    ZERO,
    POSITIVE
};

int main(void)
{
    // function declarations
    int Difference(int, int, int *);

    // variable declaration
    int a_vtg;
    int b_vtg;
    int answer_vtg, ret_vtg;

    // code
    printf("\n\n");
    printf("Enter Value Of 'A': ");
    scanf("%d", &a_vtg);

    printf("\n\n");
    printf("Enter Value Of 'B': ");
    scanf("%d", &b_vtg);

    ret_vtg = Difference(a_vtg, b_vtg, &answer_vtg);

    printf("\n\n");
    printf("Difference Of %d And %d = %d\n\n", a_vtg, b_vtg, answer_vtg);

    if (ret_vtg == POSITIVE)
        printf("The Difference Of %d And %d Is Positive !!!\n\n", a_vtg, b_vtg);
    else if (ret_vtg == NEGATIVE)
        printf("The Difference Of %d And %d Is Negative !!!\n\n", a_vtg, b_vtg);
    else
        printf("The Difference Of %d And %d Is Zero !!!\n\n", a_vtg, b_vtg);

    return (0);
}

// WE WANT OUR FUNCTION Difference() TO PERFORM 2 JOBS ...
// ONE, IS TO SUBTRACT THE INPUT NUMBERS ('y' FROM 'x')
// AND THE SECOND, IS TO TELLS WHETHER THE DIFFERENCE OF 'x' AND 'y' IS POSITIVE or NEGATIVE or ZERO ...
// BUT ANY FUNCTION HAS ONLY ONE VALID RETURN VALUE, THEN HOW CAN WE MANAGE TO RETURN TWO VALUES TO THE CALLING FUNCTION?
// THIS IS WHERE PARAMETERIZED RETURN VALUE COMES INTO THE PICTURE ...
// WE CAN RETURN THE ACTUAL DIFFERENCE OF 'x' AND 'y', THAT IS, THE ACTUAL ANSWER
// VALUE, VIA OUT-PARAMETER / PARAMETERIZED RETURN VALUE
// AND WE CAN RETURN THE STATUS OF THE ANSWER (POSITIVE / NEGATIVE / ZERO) VIA THEN ACTUAL RETURN VALUE OF THE FUNCTION ...

int Difference(int x_vtg, int y_vtg, int *diff_vtg)
{
    // code
    *diff_vtg = x_vtg - y_vtg;

    if (*diff_vtg > 0)
        return (POSITIVE);
    else if (*diff_vtg < 0)
        return (NEGATIVE);
    else
        return (ZERO);
}