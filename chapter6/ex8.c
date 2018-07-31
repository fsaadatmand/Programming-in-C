/*
 * Progam that displays all prime numbers between 1 and n = 150
 * using Sieve of Eratosthenes algorithm.  (Ver. 2)
 *
 * This version uses an array (Prime) to store the result and a variable 
 * length array to produce a clean output (without zeroes) for printf.
 * See steps 7 and 8.
 *
 * By Faisal Saadatmand
 */

#include <stdio.h>

int main(void)
{

/* Step 1: define an array of integers P. Set all elements to 
 * P[i] to 0, 2 <= i <= n */

	int  P[151], N[151], Prime[151], i, j, n, x, counter; 

	n = 150;
	counter = 0;


	for (i = 2; i <= n; ++i) {
		P[i] = 0;
		N[i] = i;
		Prime[i] = 0;
	}

/* Step 2: set i to 2 */
	i = 2;

/* Step 3: If i > n, the algorithm terminates */
	while (i < n) {

/* Step 4: If P[i] is 0, then i is prime */
		if (P[i] == 0) 
			Prime[i] = N[i];

/* Step 5: For all positive integer values of j, such
 * i x j <= n, set P[i x j] to 1. */

		for (j = 2; j <= n; ++j) {	
			if (i * j <= n)
				P[i*j] = 1;
		}
	
/* Step 6: Add 1 to i and go to step 3 */
	++i;
	}

/* Step 7: Order the Prime array */
	for (i = 2; i <= n; ++i)
		if (Prime[i] == 0) 
				++counter;
		else if (Prime[i] != 0 && counter != 0) {
			for ( x = i; x <= n; ++x )
				Prime[x-counter] = Prime[x];

			i -= counter;
			counter = 0;
		}

/* Step 8: Create a variable length array Prime2 to eliminate the zeroes at the end of Prime array. */
	x = 2;

	while ( Prime[x] != 0 )
		++x;

	unsigned int Prime2[x];

	for (i = 2; i <= x; ++i)
		Prime2[i]  = Prime[i];

/* Print the value of elements in Prime2 */

	for (i = 2; i < x ; ++i)
		printf("%i ", Prime2[i]);
	
	printf("\n");

	return 0;
}
