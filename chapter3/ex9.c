/* 
 * Program to round off an i integer to next largest even multiple of 
 * another integer j. 
 * Formula: next_multiple = i + j - i % j
 * Faisal Saadatmand 
 */

#include <stdio.h>

int main(void)
{
	int i, j;

	i = 365, j = 7;
	printf("%d next even multiple for %d is %d\n", i, j, i + j - i % j);

	i = 12258, j = 23;
	printf("%d next even multiple for %d is %d\n", i, j, i + j - i % j);

	i = 996, j = 4;
	printf("%d next even multiple for %d is %d\n", i, j, i + j - i % j);

	return 0;
}

