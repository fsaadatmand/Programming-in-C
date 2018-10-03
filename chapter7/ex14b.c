/* 
 * 14. Rewrite the functions developed in the last four exercises to use global
 * variables instead of arguments. For example, the preceding exercise should
 * now sort a globally defined array.
 * By Faisal Saadatmand
 */

#include <stdio.h>

int array[5] = { 1, 5, 21, 18, 5 };

int arraySum(int a[], int n)
{
	int i, sum = 0;

	for (i = 0; i < n; ++i)
		sum += a[i];
	return sum;
}

int main(void)
{
	int arraySum(int a[], int n);

	printf("%i\n", arraySum(array, 5));
	return 0;
}
