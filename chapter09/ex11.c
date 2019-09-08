/*
 * 11. Extend the strToInt() function from Program 9.11 so that if the first
 * character of the string is a minus sign, the value that follows is taken as
 * a negative number.
 *
 * By Faisal Saadatmand
 */

#include <stdio.h>
#include <stdbool.h>

int strToInt(const char string[])
{
	int  i, intValue, result = 0;
	bool negNumber = false;

	if (string[0] == '-') {
		i = 1;
		negNumber = true;
	} else
		i = 0;

	for (; string[i] >= '0' && string[i] <= '9'; ++i) {
		intValue = string[i] - '0';
		result = result * 10 + intValue;
	}

	if (negNumber == true)
		result *= -1;

	return result;
}

int main(void) 
{
	int strToInt(const char string[]);

	printf("%i\n", strToInt("-245"));
	printf("%i\n", strToInt("100") + 25);
	printf("%i\n", strToInt("13x5"));
	printf("%i\n", strToInt("xxx"));

	return 0;
}
