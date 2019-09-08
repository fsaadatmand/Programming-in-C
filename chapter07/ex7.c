/*
 * 7. Write a function that raises an integer to a positive integer power. Call
 * the function x_to_the_n() taking two integer arguments x and n.  Have the
 * function return a long int, which represents the results of calculating x^n.
 * By Faisal Saadatmand
 */


#include <stdio.h>

long int x_to_the_n(int x, int n)
{
	long int result = 1;

		while (n > 0) {
			result *= x;
			--n;
		}
	return result;
}

int main(void) 
{
	long int x_to_the_n(int x, int n);

	printf("Result = %li\n", x_to_the_n(2, 0));
	printf("Result = %li\n", x_to_the_n(2, 1));
	printf("Result = %li\n", x_to_the_n(2, 2));
	printf("Result = %li\n", x_to_the_n(2, 3));
	printf("Result = %li\n", x_to_the_n(2, 4));
	printf("Result = %li\n", x_to_the_n(2, 5));
	printf("Result = %li\n", x_to_the_n(2, 6));
	printf("Result = %li\n", x_to_the_n(2, 7));

	return 0;
}
