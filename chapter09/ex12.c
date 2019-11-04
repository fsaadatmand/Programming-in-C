/* 
 * 12. Write a function called strToFloat() that converts a character string
 * into a floating-point value. Have the function accept an optional leading
 * minus sign. So, the call
 *
 *		strToFloat ("-867.6921");
 *
 * should return the value −867.6921.
 *
 * by Faisal Saadatmand.
 */

#include <stdio.h>
#include <stdbool.h>

bool numeric(char);
float strToFloat(const char []);

bool numeric(char c)
{
	return c >= '0' && c <= '9';
}

float strToFloat(const char str[])
{
	int i;
	float number, divisor;
	bool negative = false;

	/* skip leading whitespaces */
	for (i = 0; str[i] == ' '; ++i)
		;

	/* handle negative numbers */
	if (str[i] == '-') {
		negative = true;
		++i;
	}

	/* digits before the decimal point */
	for ( ; numeric(str[i]); ++i)
		number = number * 10 + str[i] - '0';

	/* digits after the decimal point */
	if (str[i++] == '.')
		for (divisor = 10 ; numeric(str[i]); divisor *= 10)
			number += (str[i++] - '0') / divisor;

	if (negative)
		number = -number;

	return number;
}

int main(void) 
{
	printf("%.4f\n", strToFloat("-867.6921"));
	printf("%.2f\n", strToFloat("-245"));
	printf("%.2f\n", strToFloat("100") + 25);
	printf("%.4f\n", strToFloat("13x5"));
	printf("%.2f\n", strToFloat("   15.95"));

	return 0;
}
