/* 
 * 7. Write a function called insertString() to insert one character string
 * into another string. The arguments to the function should consist of the
 * source string, the string to be inserted, and the and the position in the
 * source string where the string is to be inerted. So, the call
 *
 *		insertString (text, "per", 10);
 *
 * with text as originally defined in the previous exercise, results in the
 * character string "per" being inserted inside text, beginning at text[10].
 * Therefore, the character string "the wrong person" is stored inside the text
 * array after the function returned.
 *
 * By Faisal Saadatmand
 */

#include <stdio.h>

void insertString(char [], const char [], int);

void insertString(char source[], const char str[], int pos)
{
	int i, str_len, src_len;

	/* find the length of str */
	for (i = 0; str[i] != '\0'; ++i)
		;
	str_len = i;

	/* find the length of source */
	for (i = 0; source[i] != '\0'; ++i)
		;
	src_len = i;

	/* make room for str by 'moving' characters from the end of source
	 * (including '\0') to right by a distance equal to str_len */
	for (i = src_len; i >= pos; --i)
		source[i + str_len] = source[i];

	/* copy str into source starting at pos */
	for (i = 0; pos < src_len && str[i] != '\0'; ++i, ++pos)
		source[pos] = str[i];
}

int main(void) 
{
	char text[30] = "the wrong son";
	
	insertString(text, "per", 10);
	printf("%s\n", text);

	return 0;
}
