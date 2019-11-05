/* 
 * 7. Program 5.10 has several inefficiencies. One inefficiency results from
 * checking even numbers. Because it is obvious that any even number greater
 * than 2 cannot be prime, the program could simply skip all even numbers as
 * possible primes and as possible divisors. The inner for loop is also
 * inefficient because the value of p is always divided by all values of d from
 * 2 through p−1. This inefficiency could be avoided by adding a test for the
 * value of isPrime in the conditions of the for loop. In this manner, the for
 * loop could be set up to continue as long as no divisor was found and the
 * value of d was less than p. Modify Program 5.10 to incorporate these two
 * changes. Then run the program to verify its operation. (Note: In Chapter 6,
 * you discover even more efficient ways of generating prime numbers.)
 *
 * By Faisal Saadatmand
 */

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	int p, d;
	bool isPrime;

	for (p = 2; p <= 50; ++p) {
		if (p == 2 || p % 2)
			isPrime = true;
		for (d = 2; isPrime && d < p; ++d)
			if (p % d == 0)
				isPrime = false;
		if (isPrime != false) {
			printf("%i ", p);
			isPrime = false;
		}
	}

	printf("\n");

	return 0;
}
	
