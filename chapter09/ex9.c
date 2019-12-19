/* 
 * 9. You can extend even further the usefulness of the replaceString()
 * function from the preceding exercise if you have it return a value that
 * indicates whether the replacement succeeded, which means that the string to
 * be replaced was found inside the source string. So, if the function returns
 * true if the replacement succeeds and false if it does not, the loop
 *
 *		do
 *		stillFound = replaceString (text, " ", "");
 *		while  ( stillFound );
 *
 * could be used to remove all blank spaces from text, for example.
 * Incorporate this change into the replaceString() function and try it with
 * various character strings to ensure that it works properly.
 *
 * by Faisal Saadatmand
 */

#include <stdio.h>
#include <stdbool.h>

#define MAXLEN 1000

/* functions */
bool replaceString(char [], const char [], const char []);
int  findString(const char [], const char []);
void removeString(char [], int, int);
void insertString(char [], const char [], int);
int  stringLength(const char []);

/* replaceString: replace string s1 with string s2 in string source. Return
 * true if the replacement succeeded and false if not. */
bool replaceString(char source[], const char s1[], const char s2[])
{
	int len, pos;

	len = stringLength(s1);
	if ((pos = findString(source, s1)) < 0)
		return false; // no match found
	removeString(source, pos, len);
	insertString(source, s2, pos);
	return true;
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

/* stringLength: return length of string s */
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
	bool stillFound = false;

 	do
 	stillFound = replaceString (text, " ", "");
 	while  ( stillFound );
	printf("%s\n", text);

	return 0;
}
