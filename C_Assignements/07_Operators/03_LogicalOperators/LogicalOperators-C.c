#include <stdio.h>

int main(void)
{
	// Variable declarations
	int a;
	int b;
	int c;
	int result;

	// Code
	printf("\n\n");
	printf("\nEnter First Integer: ");
	scanf("%d", &a);

	printf("\n\n");
	printf("\nEnter Second Integer: ");
	scanf("%d", &b);

	printf("\n\n");
	printf("\nEnter Third Integer: ");
	scanf("%d", &c);

	result = (a <= b) && (b != c);
	printf("LOGICAL AND (&&): Answer is TRUE (1) if and only if BOTH conditions are true. The Answer is FALSE (0), If Any One Or Both Conditions Are False.\n\n");
	printf("A = %d is less than or equal to B = %d AND B = %d is NOT equal to C = %d\tAnswer = %d\n\n", a, b, b, c, result);

	result = (b >= a) || (a == c);
	printf("LOGICAL OR (||): Answer is FALSE (0) if and only if BOTH conditions are false. The Answer is TRUE (1), If Any One Or Both Conditions Are True.\n\n");
	printf("Either B = %d is greater than or equal to A = %d OR A = %d is equal to C = %d\tAnswer = %d\n\n", b, a, a, c, result);

	result = !a;
	printf("A = %d and using Logical NOT (!) operator on A gives result %d\n", a, result);

	result = !b;
	printf("B = %d and using Logical NOT (!) operator on B gives result %d\n", b, result);

	result = !c;
	printf("C = %d and using Logical NOT (!) operator on C gives result %d\n", c, result);

	result = (!(a <= b) && !(b != c));
	printf("\nUsing Logical NOT (!) on (a <= b) and (b != c) and then AND-ing them afterwards gives result = %d\n", result);

	printf("\n\n");

	result = !((b >= a) || (a == c));
	printf("Using Logical NOT (!) on entire logical expression (b >= a) || (a == c) gives result = %d\n", result);

	printf("\n\n");

	return 0;
}
