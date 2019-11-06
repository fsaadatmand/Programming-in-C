/*
 * 11. Write a program that calculates the sum of the digits of an integer. For
 * example, the sum of the digits of the number 2155 is 2 + 1 + 5 + 5 or 13.
 * The program should accept any arbitrary integer typed in by the user.
 *
 * By Faisal Saadatmand
 */

#include <stdio.h>

int main(void)
{
	long long int number, sum;
	int right_digit;

	printf("Enter a number to calculate the sum of digits: ");
	scanf("%lli", &number);

	sum = 0;
	while (number != 0) {
		right_digit = number % 10;
		sum += right_digit; 
		number /= 10;
	}

	printf(" -> %lli\n", sum);

	return 0;
}
