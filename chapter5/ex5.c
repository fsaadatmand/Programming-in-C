/* 
 * Program 4.9 to reverse the digits of a number. (Ver. 2)
 * Fixed negative digits input
 */

#include <stdio.h>

int main(void)
{
	int  number,  right_digit;
	char minus_sign, zero;

	printf("Enter your number.\n");
	scanf("%i", &number);

	do {
		if (number < 0) {
			printf("%c", minus_sign = '-');
			number = -number;
			printf("%i", right_digit = number % 10);
		} else if (number >= 0)
			printf("%i", right_digit = number % 10);
		number /= 10;
	} while (number != 0);

	printf("\n");

	return 0;
}
