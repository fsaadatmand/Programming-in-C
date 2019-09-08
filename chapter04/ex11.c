/*
 * 11. Write a program that calculates the sum of the digits of an integer. For
 * example, the sum of the digits of the number 2155 is 2 + 1 + 5 + 5 or 13.
 * The program should accept any arbitrary integer typed in by the user.
 * By Faisal Saadatmand
 */

#include <stdio.h>

int main(void)
{
	long long int number, sum, right_digit, counter;

	printf("Enter a number to calculate its sum: ");
	scanf("%lli", &number);

	sum = 0;
	counter = number;

	while (counter != 0) {
		right_digit = counter % 10;
		sum += right_digit; 
		counter /= 10;
	}

	printf("The sum of %lli is %lli\n", number, sum);

	return 0;
}
