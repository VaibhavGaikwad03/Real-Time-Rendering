#include <stdio.h>

int main(void)
{
    // function declarations
    void MathematicalOperations(int, int, int *, int *, int *, int *, int *);

    // variable declaration
    int a_vtg;
    int b_vtg;
    int answer_sum_vtg;
    int answer_difference_vtg;
    int answer_product_vtg;
    int answer_quotient_vtg;
    int answer_remainder_vtg;

    // code
    printf("\n\n");
    printf("Enter Value Of 'A': ");
    scanf("%d", &a_vtg);

    printf("\n\n");
    printf("Enter Value Of 'B': ");
    scanf("%d", &b_vtg);

    // PASSING ADDRESSES TO FUNCTION ... FUNCTION WILL FILL THEM UP WITH VALUES ... HENCE, THEY GO INTO THE FUNCTION AS ADDRESS PARAMETERS AND COME OUT OF THE FUNCTION FILLED WITH VALID VALUES
    // THUS, (&answer_sum_vtg, &answer_difference_vtg, &answer_product_vtg, &answer_quotient_vtg, &answer_remainder_vtg) ARE CALLED "OUT PARAMETERS" OR "PARAMETERIZED RETURN VALUES" ... RETURN VALUES OF FUNCTIONS COMING VIA PARAMETERS
    // HENCE, ALTHOUGH EACH FUNCTION HAS ONLY ONE RETURN VALUE, USING THE CONCEPT OF "PARAMETERIZED RETURN VALUES", OUR FUNCTION "Mathematicaloperations()" HAS GIVEN US 5 RETURN VALUES!!!
    MathematicalOperations(a_vtg, b_vtg, &answer_sum_vtg, &answer_difference_vtg, &answer_product_vtg, &answer_quotient_vtg, &answer_remainder_vtg);

    printf("\n\n");
    printf("****** RESULTS ****** : \n\n");
    printf("Sum = %d\n\n", answer_sum_vtg);
    printf("Difference = %d\n\n", answer_difference_vtg);
    printf("Product = %d\n\n", answer_product_vtg);
    printf("Quotient = %d\n\n", answer_quotient_vtg);
    printf("Remainder = %d\n\n", answer_remainder_vtg);

    return (0);
}

void MathematicalOperations(int x_vtg, int y_vtg, int *sum_vtg, int *difference_vtg, int *product_vtg, int *quotient_vtg, int *remainder_vtg)
{
    // code
    *sum_vtg = x_vtg + y_vtg;        // Value at address 'sum' = (x + y)
    *difference_vtg = x_vtg - y_vtg; // Value at address 'difference' = (x - y)
    *product_vtg = x_vtg * y_vtg;    // Value at address 'product' = (x * y)
    *quotient_vtg = x_vtg / y_vtg;   // Value at address 'quotient' = (x / y)
    *remainder_vtg = x_vtg % y_vtg;  // Value at address 'remainder' = (x % y)
}