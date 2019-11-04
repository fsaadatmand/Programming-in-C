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

/* functions */
void insertString(char [], const char [], int);
void removeString(char [], int, int);
int findString(const char [], const char []);
bool replaceString(char [], const char [], const char []);

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

bool replaceString(char source[], const char s1[], const char s2[])
{
	int i, pos;

	for (i = 0; s1[i] != '\0'; ++i)
		;

	if ((pos = findString(source, s1)) < 0)
		return false;

	removeString(source, pos, i);
	insertString(source, s2, pos);

	return true;
}

int main(void) 
{
	bool stillFound;
	char text[] = "0123456789 ten eleven   .";

	do {
		/* remove all blank spaces */
		stillFound = replaceString(text," ", "");
	} while (stillFound);

	printf("%s\n", text);

	return 0;
}
