/* 
 * Function to determine if one character string exists inside another string 
 * by Faisal Saadatmand 
 * */

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
			while (search[j] != '\0' && matchFound) {
				if (search[j] != source[i]) {
					matchFound = false;
				} else
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
