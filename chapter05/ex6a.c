/* 
 * 6. Write a program that takes an integer keyed in from the terminal and
 * extracts and displays each digit of the integer in English. So, if the user
 * types in 932, the program should display
 *		nine three two Remember to display
 * “zero” if the user types in just a 0. (Note: This exercise is a hard one!)
 *
 * Attempt #2: This, I believe, is a cleaner and more efficient implementation.
 * It can also handles numbers ending with zeros, such as 100.
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
