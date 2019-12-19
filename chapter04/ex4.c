/*
 * 4. The factorial of an integer n, written n!, is the product of the
 *
 *     5!  =  5 x 4 x 3 x 2 x 1  =  120
 *
 * Write a program to generate and print a table of the first 10 factorials.
 *
 * by Faisal Saadatmand
 */

#include <stdio.h>

int main(void)
{
	int i, j, factorial;

	for (i = 0; i < 10; ++i) {
		factorial = 1;
		for (j = i; j > 1; --j)
			factorial *= j;
		printf("%2i! = %d\n", i, factorial);
	}
	return 0;
}
