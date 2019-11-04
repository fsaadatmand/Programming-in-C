/*
 * 14. Write a function called intToStr() that converts an integer value into a
 * character string. Be certain the function handles negative integers
 * properly.
 *
 * By Faisal Saadatmand
 */

#include <stdio.h>
#include <stdbool.h>

#define MAXLEN 20 

void intToStr(int, char []);

void intToStr(int number, char str[])
{
	int i, rNumber;
	bool negative = false;

	/* handle negative numbers */
	if (number < 0) {
		number = -number;
		negative = true;
	}

	/* reverse the number */
	rNumber = 0;
	while (number > 0) {
		rNumber = rNumber * 10 + number % 10;
		number /= 10;
	}

	/* copy reversed number into str */
	i = 0;
	if (negative)
		str[i++] = '-';

	while (rNumber > 0) {
		str[i++] = rNumber % 10 + '0';
		rNumber /= 10;
	}
	str[i] = '\0';
}

int main(void) 
{
	int intValue;
	char string[MAXLEN];

	printf("Enter integer value: ");
	scanf("%i", &intValue);

	intToStr(intValue, string);
	printf("%s\n", string);

	return 0;
}
