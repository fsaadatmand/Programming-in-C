/* 
 * 8. Using the findString(), removeString(), and insertString() functions from
 * preceding exercises, write a function called replaceString() that takes
 * three character string arguments
 *
 *		replaceString (source, s1, s2);
 *
 * and that replaces s1 inside source with the character string s2. The
 * function should call the findString() function to locate s1 inside source,
 * then call the removeString() function to remove s1 from source, and finally
 * call the insertString() function to insert s2 source, and finally call the
 * insertString() function to insert s2 into source at the proper location.
 * So, the function call
 *
 *		replaceString (text, "1", "one");
 *
 * replaces the first occurrence of the character string "1" inside the
 * character string text, if it exists, with the string "one". Similarly,
 *
 *		replaceString (text, "*", "");
 *
 * has the effect of removing the first asterisk inside the text array because
 * the replacement string is the null string.
 *
 * by Faisal Saadatmand
 * */

#include <stdio.h>

/* functions */
void insertString(char [], const char [], int);
void removeString(char [], int, int);
int findString(const char [], const char []);
void replaceString(char [], const char [], const char []);

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

void removeString(char source[], int pos, int count)
{	
	int i;

	for (i = pos + count; source[i] != '\0'; ++i, ++pos)
		/* copy characters to from index i to pos */
		source[pos] = source[i];
	source[pos] = '\0';
}

/* findString: to determine if one character string exists inside another
 * string */
int findString(const char source[], const char sought[])
{
	int i, j, k;

	for (i = 0; source[i] != '\0'; ++i) {
		for (j = i, k = 0; source[j] == sought[k]; ++j, ++k)
			;
		if (sought[k] == '\0') // match is found if sought reached end
			return i; // return match position in source
	}
	return -1;
}		

void replaceString(char source[], const char s1[], const char s2[])
{
	int i, pos;

	for (i = 0; s1[i] != '\0'; ++i)
		;

	pos = findString(source, s1);
	removeString(source, pos, i);
	insertString(source, s2, pos);
}

int main(void) 
{
	char text[] = "0123456789 ten *eleven.";

	replaceString(text, "1", "one");
	replaceString(text, "ten", "10");
	replaceString(text, "*", "");
	printf("%s\n", text);

	return 0;
}
