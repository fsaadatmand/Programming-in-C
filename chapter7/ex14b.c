/* Function arraySum. Using gloable variables */

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
