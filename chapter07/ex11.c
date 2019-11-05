/*
 * 11. Write a function called arraySum() that takes two arguments: an integer
 * array and the number of elements in the array. Have the function return as
 * its result the sum of the elements in the array.
 *
 * By Faisal saadatamnd
 */

#include <stdio.h>

/* functions */
int arraySum(int [], int);

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

	int array[5] = { 1, 5, 21, 18, 5 };
	printf("%i\n", arraySum(array, 5));

	return 0;
}
