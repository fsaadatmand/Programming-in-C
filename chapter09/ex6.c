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

/* functions */
void removeString(char [], int, int);
int stringLength(const char []);

/* removeString: remove n characters from string s, starting at pos */
void removeString(char s[], int pos, int n)
{	
	int i, len;

	/* copy characters (including '\0') from index i to pos */
	len = stringLength(s);
	for (i = pos + n; i <= len; ++i)
		s[pos++] = s[i];
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
	char str[] = "the wrong son";

	removeString(str, 4 , 6);
	printf("%s\n", str); 

	return 0;
}
