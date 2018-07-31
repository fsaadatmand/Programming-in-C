/* 
 * Function to insert one character string into another string
 * by Faisal Saadatmand
 * */

#include <stdio.h>

void insertString(char source[], const char inStr[], int position)
{
	int i = 0, countSource = 0, countInStr = 0;

	while (inStr[i] != '\0')   /* count number of char in inStr */
		++i;
	countInStr = i;

	while (source[i] != '\0')  /* count number of char in source */
		++i;
	countSource = i;

    /* move chars in source starting from the end, including the null char*/
	for (i = countSource; i >= position; --i)
		source[i + countInStr] = source[i];

	for (i = 0; i < countInStr; ++i) {        /* insert inStr into source */
		source[position] = inStr[i];
		++position;
	}
}

int main(void) 
{
	void insertString(char source[], const char inStr[], int position);

	char text[30] = "the wrong son";
	
	insertString(text, "per", 10);
	printf("%s\n", text);

	return 0;
}
