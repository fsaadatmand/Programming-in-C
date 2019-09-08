/* Modified program to generate prime numbers */

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	int p, i, primes[50], primeIndex = 2;
	bool isPrime;

	primes[0] = 2;
	primes[1] = 3;

	for (p = 5; p <= 50; p = p + 2) {
		isPrime = true;
		for (i = 1; isPrime && p / primes[i] >= primes[i]; ++i)
			if (p % primes[i] == 0)
				isPrime = false;
		if (isPrime == true) {
			primes[primeIndex] = p;
			++primeIndex;
		}
	}

	for (i = 0; i < primeIndex; ++i)
		printf("%i   ", primes[i]);

	printf("\n");

	return 0;
}
