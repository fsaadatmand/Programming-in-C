/* Calculating the nth triangular number using functions */

#include <stdio.h>

int calculateTriangularNumber(int n)
{
	int i, triangularNumber = 0;
	for (i = 0; i <= n; ++i)
		triangularNumber += i;

	return triangularNumber;
}

int main(void)
{
    int number, right_digit;
	int calculateTriangularNumber(int n);

    printf("Enter your number.\n");
    scanf("%i", &number);

	printf("Triangular number for %i is %i\n", number, calculateTriangularNumber(number));

    return 0;
}
