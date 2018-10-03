/* 
 * 5. You developed Program 4.9 to reverse the digits of an integer typed in
 * from the terminal. However, this program does not function well if you type
 * in a negative number. Find out what happens in such a case and then modify
 * the program so that negative numbers are correctly handled. For example, if
 * the number −8645 is typed in, the output of the program should be 5468−.
 *
 * This version uses two if statements rather than the else-if construct. It
 * has a 1 line of code less.
 * By Faisal Saadatmand
 */
#include <stdio.h>

int main()
{
	int  number,  right_digit;
	char minus_sign;

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
