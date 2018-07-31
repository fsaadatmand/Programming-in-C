/* 
 * Function to extract a portion of a character string 
 * by Faisal Saadatmand
 * */

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
