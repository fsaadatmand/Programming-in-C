/*
 * 6. Write a function called removeString() to remove a specified number of
 * characters from a character string. The function should take three
 * arguments: the source string, the starting index number in the source
 * string, and the number of characters to remove. So, if the character array
 * text contains the string "the wrong son", the call
 *
 *		removeString (text, 4, 6);
 *
 * has the effect of removing the characters “wrong” (the word “wrong” plus the
 * space that follows) from the array text. The resulting string inside text is
 * then "the son".
 *
 * by Faisal Saadatmand
 */

#include <stdio.h>

void removeString(char [], int, int);

void removeString(char source[], int pos, int n)
{	
	int i, len;

	/* find the length of str */
	for (i = 0; source[i] != '\0'; ++i)
		;
	len = i;

	/* copy characters (including '\0') to from index i to pos  */
	for (i = pos + n; i <= len; ++i)
		source[pos++] = source[i];
}

int main(void) 
{	
	char str[] = "the wrong son";

	removeString(str, 4 , 6);
	printf("%s\n", str); 

	return 0;
}
