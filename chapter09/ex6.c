/*
 * 6. Write a function called removeString() to remove a specified number of
 * characters from a character string. The function should take three
 * arguments: the source string, the starting index number in the source
 * string, and the number of characters to remove. So, if the character array
 * text contains the string "the wrong son", the call
 *
 *		removeString (text, 4, 6);
 *
 * has the effect of removing the characters “wrong” (the word “wrong” plus the
 * space that follows) from the array text. The resulting string inside text is
 * then "the son".
 *
 * by Faisal Saadatmand
 */

#include <stdio.h>

void removeString(char source[], int index, int nchar)
{	
	int i;

	i = index + nchar;
	while (source[i] != '\0') {      /* remove word */
		source[index] = source[i];
		++index;
		++i;
	}

	while (source[index] != '\0') {  /* remove spaces */
		source[index] = '\0';
		++i;
	}
}

int main(void) 
{
	void removeString(char source[], int index, int nchar);

	int i = 0;
	char text[] = "the wrong son";

	removeString(text, 4, 6);
	printf("%s\n", text); 

	while (text[i] != '\0') {     /* test for the null character at the end of
									 string */
		printf("%c", text[i]);
		++i;
	}

	printf("\n");

	return 0;
}
