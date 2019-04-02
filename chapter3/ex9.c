/* 9. Write a program to find the next largest even multiple for the following
 * values of i and j:
 *		i        j
 * 		356      7
 *		12,258   23
 *		996      4
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

