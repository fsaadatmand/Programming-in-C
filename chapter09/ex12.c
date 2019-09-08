/* 
 * 12. Write a function called strToFloat() that converts a character string
 * into a floating-point value. Have the function accept an optional leading
 * minus sign. So, the call
 *		strToFloat ("-867.6921");
 * should return the value −867.6921.
 *
 * by Faisal Saadatmand.
 */

#include <stdio.h>
#include <stdbool.h>

float strToInt(const char string[])
{
	int   i, decimalPoint = 1; 
	float floatValue, preDecimal = 0.0, postdecimal = 0.0, result = 0.0;
	bool  negNumber = false;

	if (string[0] == '-') {
		i = 1;
		negNumber = true;
	} else
		i = 0;

	for (; string[i] >= '0' && string[i] <= '9' && string[i] != 46; ++i) {
		floatValue = string[i] - '0';
		preDecimal = preDecimal * 10.0 + floatValue;
	}
	
	if (string[i] == 46)                     /* decimal point */
	for (++i; string[i] >= '0' && string[i] <= '9'; ++i) {
		floatValue = string[i] - '0';
		postdecimal = postdecimal * 10.0 + floatValue;
		decimalPoint *= 10;
	}

    result = preDecimal + postdecimal / decimalPoint;

	if (negNumber == true)
		result *= -1.0;

	return result;
}

int main(void) 
{
	float strToInt(const char string[]);

	printf("%.4f\n", strToInt("-867.6921"));
	printf("%.4f\n", strToInt("-245"));
	printf("%.4f\n", strToInt("100") + 25);
	printf("%.4f\n", strToInt("13x5"));

	return 0;
}
