/* 
 * 4. Write a function called substring() to extract a portion of a character
 * string. The function should be called as follows:
 *
 *		substring (source, start, count, result);
 *
 *	where source is the character string from which you are extracting the
 *	substring, start is an index number into source indicating the first
 *	character of the substring, count is the number of characters to be
 *	extracted from the source string, and result is an array of characters that
 *	is to contain the extracted substring. For example, the call
 *
 *		substring ("character", 4, 3, result);
 *
 * extracts the substring "act" (three characters starting with character
 * number 4) from the string "character" and places the result in result.  Be
 * certain the function inserts a null character at the end of the substring in
 * the result array. Also, have the function check that the requested number of
 * characters does, in fact, exist in the string. If this is not the case, have
 * the function end the substring when it reaches the end of the source string.
 * So, for example, a call such as
 *
 *		substring ("two words", 4, 20, result);
 *
 * should just place the string “words” inside the result array, even though 20
 * characters were requested by the call.
 *
 * by Faisal Saadatmand
  */

#include <stdio.h>

void substring(const char source[], int start, int count, char result[])
{
	int i, j = 0, nChar =0;

	while (source[nChar] != '\0')     /* count number of characters in source */
		++nChar;

	if (start + count > nChar) {      /* extract till the end of source */
		i = start;
		while (source[i] != '\0') {
			result[j] = source[i];
			++i;
			++j;
		}
	} else                        /* extract the requested number of characters */
		for (i = start; i < start + count; ++i) {
			result[j] = source[i];
			++j;
		}	

	result[j] = '\0';
}

int main(void) 
{
	void substring(const char source[], int start, int count, char result[]);

	char result[20];
	const char array[] = "character";

	substring(array, 4, 3, result);
	
	printf("%s\n", result);

	return 0;
}
