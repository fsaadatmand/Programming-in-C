/* 
 * Program to extract a each typed-in digit of an integer and display it
 * in English. For example, 932 to nine three two.  Attempt #2. This is a
 * cleaner and (I believe) a more efficient code. It also handles numbers
 * ending with zeros, such as 100.
 * by Faisal Saadatmand
 */

#include <stdio.h>

int main(void)
{
	int number, rightDigit, nZeros = 0, reversedNumber = 0;

	printf("Enter a number ");
	scanf("%d", &number);

	/* If number is 0, simply print zero */
	if (number == 0)
		printf("zero ");

	/* check if the number ends with zeros. If yes, extract and count the zeros.
	 * We'll be printed later. */
	while (number != 0 && number % 10 == 0) {
		rightDigit = number % 10;
		++nZeros;
		number /= 10;
	} 

	/* Reverse the remaining digits in number */
	while (number > 0) {
		rightDigit = number % 10;
		reversedNumber *=10;
		reversedNumber += rightDigit;
		number /= 10;
	}

	/* Display the digits of the reversed number in English words */
	while (reversedNumber > 0) {
		rightDigit = reversedNumber % 10;
		switch (rightDigit) {
		case 0:
			printf("zero ");
			break;
		case 1:
			printf("one ");
			break;
		case 2:
			printf("two ");
			break;
		case 3:
			printf("three ");
			break;
		case 4:
			printf("four ");
			break;
		case 5:
			printf("five ");
			break;
		case 6:
			printf("six ");
			break;
		case 7:
			printf("seven ");
			break;
		case 8:
			printf("eight ");
			break;
		case 9:
			printf("nine ");
			break;
		default:
			printf("Unknown character");
		}
		reversedNumber /= 10;
	}
	
	/* Print zeros for numbers ending with one or more zeros */
	while (nZeros > 0) {
		printf("zero ");
		--nZeros;
	}

	printf("\n");

	return 0;
}
