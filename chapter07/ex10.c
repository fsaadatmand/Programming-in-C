/* 
 * 10. Write a function prime() that returns 1 if its argument is a prime
 * number and returns 0 otherwise.
 *
 * By Faisal Saadatmand
 */

#include <stdio.h>
#include <stdbool.h>

/* functions */
bool prime(int);

bool prime(int number)
{
	int i;

   /* Exclude all numbers under 2 and all even numbers.
	* 2 is a special case: though it's even, it's a prime. */
	if (number != 2 && (number < 2 || number % 2 == 0))
		return false;
	/* check if number is divisible by any number other than itself */
	for (i = 3; i < number - 1; i += 2) 	
		if (number % i == 0)
			return false;

	return true;
}

int main (void)
{
	int number, input;

	while (true) {
		printf("Enter a number to check for primality: ");
		if (!(input = scanf("%i", &number)) || input == EOF)
			break;
		printf(" %i %s a prime number.\n", number,
				(prime(number)) ? "is" : "is NOT");
	}

	return 0;
}

