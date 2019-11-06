/*
 * 7. Write a function that raises an integer to a positive integer power. Call
 * the function x_to_the_n() taking two integer arguments x and n.  Have the
 * function return a long int, which represents the results of calculating x^n.
 *
 * By Faisal Saadatmand
 */

#include <stdio.h>

/* functions */
long int x_to_the_n(int, int);

long int x_to_the_n(int x, int n)
{
	int i;
	long int result;

	result = 1;
	for (i = 0; i < n; ++i)
		result *= x;

	return result;
}

int main(void) 
{
	int x, n;
	
	for (n = 0, x = 2; n < 8; ++n) 
		printf("%i^%i = %li\n", x, n , x_to_the_n(x, n));

	return 0;
}
