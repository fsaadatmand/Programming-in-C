/* 
 * function (prime) that returns 1 if its argument is a prime number
 * and returns 0 otherwise. Using gloable variables.
 * By Faisal Saadatmand
 */

#include <stdio.h>
#include <stdbool.h>

int gNumber;

int prime(int number)
{
	int i;
	bool isPrime = true;

	if (number == 2)    /* exclude 2 otherwise it will be wrongly flagged as
						   an even number */
		isPrime = true;
	else if (number < 2 || number % 2 == 0)    /* exclude negative numbers,
												  0, 1 and even numbers */
			isPrime = false;
	else
		for (i = 3; i < number - 1; ++i)
			if (number % i == 0)    /* remainder of number divided by i is 0 */ 
				return 0;
			else
				isPrime = true;	

	return isPrime;
}

int main(void)
{
	int prime(int number);
	
	printf("Enter a number to test primality: ");
	scanf("%i", &gNumber);
	printf("%i\n", prime(gNumber));

	return 0;
}

