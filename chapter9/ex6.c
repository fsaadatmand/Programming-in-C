/*
 * Function to remove a specified number of charachters from
 * a character string
 * by Faisal Saadatmand
 * */

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
