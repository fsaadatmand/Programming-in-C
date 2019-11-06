/*
 * 2. Write a program to generate and display a table of n and n^2, for integer
 * values of n ranging from 1 to 10. Be certain to print appropriate column
 * headings.
 *
 * by Faisal Saadatmand
 */

#include <stdio.h>

int main(void)
{
	int n;

	printf(" n       n^2\n");
	printf("----\t----\n");		

	for (n = 1; n <= 10; ++n)
		printf("%2i\t%3i\n", n, n * n);

	return 0;
}
