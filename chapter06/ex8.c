/*
 * 8. Find out if your compiler supports variable-length arrays. If it does,
 * write a small program to test the feature out.
 *
 * By Faisal Saadatmand
 */

#include <stdio.h>

int main(void)
{
	unsigned long n, i;

	printf("Enter a value of n to Generate the first n Fibonacci numbers: ");
	scanf("%lu", &n);

	/* array's depends on the user's input */
	unsigned long long Fibonacci[n];

	Fibonacci[0] = 0;
	Fibonacci[1] = 1;

	for (i = 2; i < n; ++i)
		Fibonacci[i] = Fibonacci[i - 2] + Fibonacci [i - 1];

	for (i = 0; i < n; ++i)
		printf("%llu\n", Fibonacci[i]);

	return 0;
}
