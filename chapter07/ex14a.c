/* 
 * 14. Rewrite the functions developed in the last four exercises to use global
 * variables instead of arguments. For example, the preceding exercise should
 * now sort a globally defined array.
 *
 * By Faisal Saadatmand
 */

#include <stdio.h>
#include <stdbool.h>

int gNumber; /* global variable */

bool prime();

bool prime()
{
	int i;

   /* Exclude all numbers under 2 and all even numbers.
	* 2 is a special case: though it's even, it's a prime. */
	if (gNumber != 2 && (gNumber < 2 || gNumber % 2 == 0))
		return false;
	/* check if gNumber is divisible by any number other than itself */
	for (i = 3; i < gNumber - 1; i += 2)
		if (gNumber % i == 0)
			return false;

	return true;
}

int main(void)
{
	int number, input;
	
	do {
		printf("Enter a number to check for primality: ");
		input = scanf("%i", &number);
		if (prime())
			printf(" %i is a prime number\n", number);
		else
			printf(" %i is not a prime number\n", number);
	} while (input && input != EOF);

	return 0;
}
