/* 
 * 7. Write a function called insertString() to insert one character string
 * into another string. The arguments to the function should consist of the
 * source string, the string to be inserted, and the position in the
 *
 *		insertString (text, "per", 10);
 *
 * with text as originally defined in the previous exercise, results in the
 * character string "per" being inserted inside text, beginning at text[10].
 * Therefore, the character string "the wrong person" is stored inside the text
 * array after the function returned.
 *
 * by Faisal Saadatmand
 * */

#include <stdio.h>

void insertString(char [], const char [], int);

void insertString(char source[], const char str[], int pos)
{
	int i , len, offset, end;

	/* find the length of str */
	for (len = 0; str[len] != '\0'; ++len)
		;

	/* copy characters starting at pos to the right by offset value */
	offset = end = pos + len;
	for (i = pos; i < end; ++i, ++offset)
		source[offset] = source[i];

	/* copy str into source starting at pos */
	for (i = 0; str[i] != '\0'; ++i, ++pos)
		source[pos] = str[i];
}

int main(void) 
{
	char text[30] = "the wrong son";
	
	insertString(text, "per", 10);
	printf("%s\n", text);

	return 0;
}
