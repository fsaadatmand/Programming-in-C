/* 
 * 6. Write a program that takes an integer keyed in from the terminal and
 * extracts and displays each digit of the integer in English. So, if the user
 * types in 932, the program should display
 *
 *		nine three two
 *
 * Remember to display “zero” if the user types in just a 0. (Note: This
 * exercise is a hard one!)
 *
 * By Faisal Saadatmand
 */

#include <stdio.h>

int main(void)
{
	int number, reversed_number, right_digit, trailing_zeros;

	printf("Enter a number: ");
	scanf("%d", &number);

	/* If number is 0, simply print zero */
	if (number == 0)
		printf("zero");

	/* extract and count trailing 0's if any */
	trailing_zeros = 0;
	while (number != 0 && (number % 10) == 0) {
		++trailing_zeros;
		number /= 10;
	}

	/* reverse the remaining integer */
	reversed_number = 0;
	while (number > 0) {
		right_digit = number % 10;
		reversed_number = reversed_number * 10 + right_digit;
		number /= 10;
	}

	/* print reversed integer from right to left in english words */
	while (reversed_number > 0) {
		right_digit = reversed_number % 10;
		switch (right_digit) {
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
			break;
		}
		reversed_number /= 10;
	}
	/* print trailing 0's if any */
	while (trailing_zeros--) {
		printf("zero ");
	}
	printf("\n");

	return 0;
}
