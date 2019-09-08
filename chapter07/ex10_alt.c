/* 
 * 10. Write a function prime() that returns 1 if its argument is a prime
 * number and returns 0 otherwise. This version uses Sieve of Eratosthenes
 * algorithm.
 * By Faisal Saadatmand
 */

#include <stdio.h>
#include <stdbool.h>

int prime(const int number) 
{
	int n = number + 1;
	int  P[n+1], N[n+1], Prime[n+1], i, j, x, counter; 
	bool isPrime;

	counter = 0;
	for (i = 2; i <= n; ++i) {
		P[i] = 0;
		N[i] = i;
		Prime[i] = 0;
	}

	i = 2;
	while (i < n) {
		if (P[i] == 0) 
			Prime[i] = N[i];
		for (j = 2; j <= n; ++j)	
			if (i * j <= n)
				P[i*j] = 1;
		++i;
	}

	for (i = 2; i <= n; ++i) {
		if (Prime[i] == 0) 
				++counter;
		else if (Prime[i] != 0 && counter != 0) {
			for (x = i; x <= n; ++x)
				Prime[x-counter] = Prime[x];
			i -= counter;
			counter = 0;
		}
	}

/* Step 8: Create a variable length array Prime2 to eliminate the zeroes at the
 * end of Prime array. */
	x = 2;
	while (Prime[x] != 0)
		++x;
	
	unsigned int Prime2[x];
	for (i = 2; i <= x; ++i)
		Prime2[i]  = Prime[i];

/* Print the value of elements in Prime2 */
	isPrime = true;

	for (i = 2; i < x ; ++i)
		if (Prime2[i] == number)
			isPrime = true;
		else
			isPrime = false;

	if (isPrime == true)
		return 1;

	return 0;
}

int main(void)
{
	int number;
	
	int prime(const int number);

	printf("Enter number to test primality: ");
	scanf("%i", &number);

	printf("%i\n", prime (number));

	return 0;
}
