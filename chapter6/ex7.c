/*
 * Progam that displays all prime numbers between 1 and n = 150
 * using Sieve of Eratosthenes algorithm
 * By Faisal Saadatmand
 */

#include <stdio.h>

int main(void) {

/* Step 1: define an array of integers P. Set all elements to 
 * P[i] to 0, 2 <= i <= n */

	int  P[151], N[151], i, j, n;

	n = 150;

	for (i = 2; i <= n; ++i) {
		P[i] = 0;
		N[i] = i;
	}

/* Step 2: set i to 2 */
	i = 2;

/* Step 3: If i > n, the algorithm terminates */
	while (i < n) {

/* Step 4: If P[i] is 0, then i is prime */
		if (P[i] == 0)
			printf("%i ", N[i]);

/* Step 5: For all positive integer values of j, such
 * i x j <= n, set P[i x j] to 1. */

		for (j = 2; j <= n; ++j)
			if (i * j <= n)
				P[i*j] = 1;

/* Step 6: Add 1 to i and got to step 3. */
	++i;
	}

	printf("\n");

	return 0;
}
