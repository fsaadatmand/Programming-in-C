/* Calculating the nth triangular number */

#include <stdio.h>


void calculateTriangularNumber(int n)
{
	int i, triangularNumber = 0;

	for (i = 0; i <= n; ++i)
		triangularNumber += i;

	printf("Triangular number %i is %i\n", n, triangularNumber);
}

int main(void)
{
	calculateTriangularNumber(10);
	calculateTriangularNumber(20);
	calculateTriangularNumber(50);

	return 0;
}
