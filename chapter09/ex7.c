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

#define MAXLEN 1000

/* functions */
void insertString(char [], const char [], int);
int stringLength(const char []);

/* insertString: insert string t into string s at index pos */
void insertString(char s[], const char t[], int pos)
{
	int i, s_len, offset;

	s_len = stringLength(s);
	/* check if pos is within the range of s */
	if (pos > s_len)
		return; // do nothing 

	/* make room for str by 'moving' characters (including '\0') from the end
	 * of s to the right by a distance equal to s_len */
	offset = stringLength(t);
	for (i = s_len + 1; i >= pos; --i)
		s[i + offset] = s[i];

	/* copy str into s starting at pos */
	for (i = 0; t[i] != '\0'; ++i, ++pos)
		s[pos] = t[i];
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
	char text[MAXLEN] = "the wrong son";
	
	insertString(text, "per", 10);
	printf("%s\n", text);

	return 0;
}
