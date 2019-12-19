/*
 * 14. Write a function called intToStr() that converts an integer value into a
 * character string. Be certain the function handles negative integers
 * properly.
 *
 * By Faisal Saadatmand
 */

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAXLEN 100 

/* functions */
void intToStr(int, char []);
double absoluteValue(double);
int stringLength(const char []);
void reverse(char []);

/* intToStr: convert number from an int to a string. Store the result in str */
void intToStr(int number, char str[])
{
	int i, digit;
	bool negative = false;

	if (number < 0) /* remember negative sign */
		negative = true;

	i = 0;
	do { /* use do while loop to account for the number 0 */
		digit = absoluteValue(number % 10); /* extract right digit */
		str[i++] = digit + '0'; /* store as char in str */
		number /= 10; /* delete digit */
	} while (number != 0);

	if (negative == true) /* insert negative sign */
		str[i++] = '-';
	str[i] = '\0';

	/* reverse the string */
	reverse(str);
}

/* absoluteValue: return the absolute value of x */
double absoluteValue(double x)
{
	return (x < 0) ? -x : x;
}

/* reverse: reverse the order of characters in string s */
void reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = stringLength(s) - 1; i < j; ++i, --j) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

/* stringLength: return the length of string s */
int stringLength(const char s[])
{
	int i;

	for (i = 0; s[i] != '\0'; ++i)
		;
	return i;
}

int main(void) 
{
	char str[MAXLEN];

	intToStr(42, str);
	printf("%s\n", str);
	intToStr(-42, str);
	printf("%s\n", str);
	intToStr(INT_MAX, str);
	printf("%s\n", str);
	intToStr(INT_MIN, str);
	printf("%s\n", str);
	intToStr(0, str);
	printf("%s\n", str);

	return 0;
}
