/* 
 * Program 4.9 to reverse the digits of a number. (Ver. 2.1)
* Fix negative digits input (alternative version)
* This version uses two if statements rather than the else-if construct. 
* It is has a 1 line of code less but I think it is also a little harder to read and debug.
*/

#include <stdio.h>

int main()
{
	int  number,  right_digit;
	char minus_sign, zero;

	printf("Enter your number.\n");
	scanf("%i", &number);

	do {
		if (number < 0) {
			printf("%c", minus_sign = '-');
			number = -number;
		}
		
		if (number >= 0)
			printf("%i", right_digit = number % 10);

		number /= 10;
	} while (number != 0);

	printf("\n");

	return 0;
}
