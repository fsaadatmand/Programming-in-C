/*
 * 13. If c is a lowercase character, the expression
 *
 *		c – 'a' + 'A'
 *
 * produces the uppercase equivalent of c, assuming an ASCII character set.
 * Write a function called uppercase() that converts all lowercase characters
 * in a string into their uppercase equivalents.
 *
 * by Faisal Saadatmand
 */

#include <stdio.h>

void uppercase(char string[])
{
	int i;

	for (i = 0; string[i] != '\0'; ++i)
		if (string[i] >= 'a' && string[i] <= 'z')
			string[i] = string[i] - 'a' + 'A';
}

int main(void) 
{
	void uppercase(char string[]);	

	char str[] = "abcdfghijklmnopqrstuvwxyz";
	uppercase(str);
	printf("%s\n", str);

	return 0;
}
