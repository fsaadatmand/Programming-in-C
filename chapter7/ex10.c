/* 
 * function (prime) that returns 1 if its argument is a prime number
 * and returns 0 otherwise.
 * By Faisal Saadatmand
 */

#include <stdio.h>
#include <stdbool.h>

int prime(int number)
{
	int i;
	bool isPrime = true;

	if (number == 2)    /* exclude 2 otherwise it will be wrongly flaged as 
						   an even number */ 
		isPrime = true;
	else if (number < 2 || number % 2 == 0)    /* exclude negative numbers,
												  0, 1 and even numbers */
			isPrime = false;
	else  
		for (i = 3; i < number - 1; ++i) 	
			if (number % i == 0)
				return 0;
			else
				isPrime = true;	
	
	return isPrime;
}

int main (void)
{
	int i; 

	int number;
	int prime(int number);
	
	printf("Enter number to test for  primality: ");
	scanf("%i", &number);

	printf("%i\n", prime(number));
	
	return 0;
}

