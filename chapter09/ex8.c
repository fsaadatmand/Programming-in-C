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
 * call the insertString() function to insert s2 into source at the proper
 * location. So, the function call
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
 * By Faisal Saadatmand
 */

#include <stdio.h>

#define MAXLEN 1000

/* functions */
void replaceString(char [], const char [], const char []);
int  findString(const char [], const char []);
void removeString(char [], int, int);
void insertString(char [], const char [], int);
int  stringLength(const char []);

/* replaceString: replace string s1 with string s2 in string source. */
void replaceString(char source[], const char s1[], const char s2[])
{
	int len, pos;

	len = stringLength(s1);
	if ((pos = findString(source, s1)) < 0)
		return; // no match found
	removeString(source, pos, len);
	insertString(source, s2, pos);
}

/* findString: return string t index position in string s if found, otherwise
 * return -1 */
int findString(const char s[], const char t[])
{
	int i, j, k;

	for (i = 0; s[i] != '\0'; ++i) {
		for (j = i, k = 0; s[j] != '\0' && s[j] == t[k]; ++j, ++k)
			;
		if (t[k] == '\0') /* found match */
			return i; /* return position of match */
	}
	return -1; /* match not found */
}		

/* removeString: remove n characters from string s, starting at pos */
void removeString(char s[], int pos, int n)
{	
	int i, len;

	/* copy characters (including '\0') from index i to pos */
	len = stringLength(s);
	for (i = pos + n; i <= len; ++i)
		s[pos++] = s[i];
}

/* insertString: insert string t into string s at index pos */
void insertString(char s[], const char t[], int pos)
{
	int i, s_len, offset;

	s_len = stringLength(s);
	/* check if pos is within the range of s */
	if (pos > s_len)
		return; // do nothing 

	/* make room for t by 'moving' characters (including '\0') from the end
	 * of s to the right by a distance equal to s_len */
	offset = stringLength(t);
	for (i = s_len + 1; i >= pos; --i)
		s[i + offset] = s[i];

	/* copy t into s starting at pos */
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
	char text[MAXLEN] = "0123456789 ten *eleven.";

	replaceString(text, "1", "one");
	replaceString(text, "ten", "10");
	replaceString(text, "*", "");
	replaceString(text, "eleven", "11");
	replaceString(text, "0", "");
	replaceString(text, "bee", "11"); /* bee is not in text */
	replaceString(text, ".", "");
	replaceString(text, " ", "");
	printf("%s\n", text);

	return 0;
}
