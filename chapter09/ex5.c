/* 
 * 5. Write a function called findString() to determine if one character string
 * exists inside another string. The first argument to the function should be
 * the character string that is to be searched and the second argument is the
 * string you are interested in finding. If the function finds the specified
 * string, have it return the location in the source string where the string
 * was found. If the function does not find the string where the string was
 * found. If the function does not find the string, have it return −1. So, for
 * example, the call
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
#include <stdbool.h>

int findString(const char source[], const char search[])
{
	int i = 0, j = 0, position = 0;
	bool matchFound = false;

	while (source[i] != '\0') {
		if (source[i] == search[j]) {
			matchFound = true;
			position = i;
			while (search[j] != '\0' && matchFound)
				if (search[j] != source[i])
					matchFound = false;
				else {
					++j;
					++i;
				}	
			if (matchFound == true)
				return position;          /* found a match */
			else {                        /* reset indexes for the outter loop */
				i = position;
				++i;
				j = 0;
			} 
		} else                           /* keep searching in source */
			++i;
	}

	if (source[i] == '\0' && matchFound == false)
		 position = -1;

	return position;
}		

int main(void) 
{
	int findString(const char source[], const char search[]);

	const char str1[] = "a chatterbox";
	const char str2[] = "hat";

	printf("%i\n", findString(str1, str2));
	printf("%i\n", findString("a chatterbox", "hat"));
	printf("%i\n", findString("a chatterbox", "car"));
	printf("%i\n", findString("a chatterbox", "ter"));

	return 0;
}
