/*
 * Program to generate the first 15 Fibonacci numbers
 * exercise 6: rewrite the program without the use of arrays
 * By Faisal Saadatmand
 */

#include <stdio.h>

int main(void)
{
	int FibCurrent, FibPrevious1, FibPrevious2, i;

	FibPrevious1 = 0;    /* by definition */
	FibPrevious2 = 1;    /* by definition */

	printf("%i\n%i\n", FibPrevious1, FibPrevious2);

	for (i = 2 ; i < 15; ++i) {
		FibCurrent   = FibPrevious1 + FibPrevious2;
		FibPrevious1 = FibPrevious2;
		FibPrevious2 = FibCurrent;
		printf("%i\n", FibCurrent);
	}

	return 0;
}
