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

int main(void) 
{
	printf("%i\n", findString("a chatterbox", "hat"));
	printf("%i\n", findString("a chatterbox", "car"));
	printf("%i\n", findString("a chatterbox", "ter"));
	printf("%i\n", findString("a chatterbox", "a chatterboxer"));

	return 0;
}
