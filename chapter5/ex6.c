/* 
 * Program to extract each typed-in digit of the integer and display it
 * in English. For example, 932 to nine three two. Attempt #1
 * While this code works, I wrote a better way that also
 * can handle numbers ending with zeros. see ex6a.c
 * By Faisal Saadatmand
  */

#include <stdio.h>

int main(void)
{
	int number, number_temp, number_of_digits, right_number, multiplier, reversed_number, n;
	char english_word;

	printf("Enter a number: ");
	scanf("%d", &number);

	number_temp = number;
	multiplier = 0;
	number_of_digits = 0;
	reversed_number = 0;

/* The role of the initial loop is twofold: 
 * 1. to count the number of digits in the typed-in number; 
 * 2. calculate a  multiplier variable based on the number of digits. */ 
	do {
		right_number = number_temp % 10;
		number_temp /= 10;
		++number_of_digits;

		if (multiplier == 0)
			multiplier = 1;
		else
			multiplier *= 10;
	} while (number_temp != 0);

/* This loop uses the multiplier from the previous loop to store the number in reverse in  variable "reversed_number".  */
	for (n = 1; n <= number_of_digits; ++n) {
		right_number = number % 10;
		right_number *= multiplier ;
		reversed_number += right_number;
		number /= 10;
		multiplier /= 10;
	}

/* final loop to reads and prints the each digit from the reveresed number--from right to left--and converts it to the equivalent English words, which will give us the desired result */
	do {
		right_number = reversed_number % 10;

		if (right_number == 0 )
			printf("zero ");
		else if (right_number == 1)
			printf("one ");
		else if (right_number == 2)
			printf("two ");
		else if (right_number == 3)
			printf("three ");
		else if (right_number == 4)
			printf("four ");
		else if (right_number == 5)
			printf("five ");
		else if (right_number == 6)
			printf("six ");
		else if (right_number == 7)
			printf("seven ");
		else if (right_number == 8)
			printf("eight ");
		else if (right_number == 9)
			printf("nine ");
		reversed_number /= 10;
		} while (reversed_number != 0);

	printf("\n");

	return 0;
}

