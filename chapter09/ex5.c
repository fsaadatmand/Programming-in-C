/* 
 * 5. Write a function called findString() to determine if one character string
 * exists inside another string. The first argument to the function should be
 * the character string that is to be searched and the second argument is the
 * string you are interested in finding. If the function finds the specified
 * string, have it return the location in the source string where the string
 * was found. If the function does not find the string, have it return −1. So,
 * for example, the call
 *
 *		index = findString ("a chatterbox", "hat");
 *
 *	searches the string "a chatterbox" for the string "hat". Because "hat" does
 *	exist inside the source string, the function returns 3 to indicate the
 *	starting position inside the source string where "hat" was found.
 *
 * by Faisal Saadatmand 
 */

#include <stdio.h>

int findString(const char [], const char []);

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

int main(void) 
{
	printf("%i\n", findString("a chatterbox", "hat"));
	printf("%i\n", findString("a chatterbox", "car"));
	printf("%i\n", findString("a chatterbox", "ter"));
	printf("%i\n", findString("a chatterbox", "a chatterboxer"));
	printf("%i\n", findString("a chatterbox", "x"));

	return 0;
}
