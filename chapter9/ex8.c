/* 
 * 8. Using the findString(), removeString(), and insertString() functions from
 * preceding exercises, write a function called replaceString() that takes
 * three character string arguments
 *
 *		replaceString (source, s1, s2);
 *
 * and that replaces s1 inside source with the character string s2. The
 * function should call the findString() function to locate s1 inside source,
 * then call the removeString() function to remove s1 from source, and finally
 * call the insertString() function to insert s2 source, and finally call the
 * insertString() function to insert s2 into source at the proper location.
 * So, the function call
 *
 *		replaceString (text, "1", "one");
 *
 * replaces the first occurrence of the character string "1" inside the
 * character string text, if it exists, with the string "one". Similarly,
 *
 *		replaceString (text, "*", "");
 *
 * has the effect of removing the first asterisk inside the text array because
 * the replacement string is the null string.
 *
 * by Faisal Saadatmand
 * */

#include <stdio.h>
#include <stdbool.h>

/* Function to determine if one character string exists inside another string */
int findString(char source[], const char search[])
{
	int i = 0, j = 0, position = 0;
	bool matchFound = false;

	while (source[i] != '\0') {
		if (source[i] == search[j]) {
			matchFound = true;
			position = i;
			while (search[j] != '\0' && matchFound)
				if (search[j] != source[i]) {
					matchFound = false;
				} else {
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

/* Function to remove a specified number of charachters from */
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

/* Function to insert one character string into another string */
void insertString(char source[], const char inStr[], int position)
{
	int i = 0, countSource = 0, countInStr = 0;

	while (inStr[i] != '\0')   /* count number of char in inStr */
		++i;
	countInStr = i;

	while (source[i] != '\0')  /* count number of char in source */
		++i;
	countSource = i;

	/* move chars in source starting from the end, including the null char */
	for (i = countSource; i >= position; --i) 
		source[i + countInStr] = source[i];

	for (i = 0; i < countInStr; ++i) {           /* insert inStr into source */
		source[position] = inStr[i];
		++position;
	}
}

void replaceString(char source[], const char s1[], const char s2[])
{
	int findString(char source[], const char search[]);
	void removeString(char source[], int index, int nchar);
	void insertString(char source[], const char inStr[], int position);

	int i = 0, position;

	while (s1[i] != '\0')
		++i;

	position = findString(source, s1);
	removeString(source, position, i);
	insertString(source, s2, position);
}

int main(void) 
{
	void replaceString(char source[], const char s1[], const char s2[]);

	char text[30] = "0123456789 ten *eleven.";

	replaceString(text, "1", "one");
	replaceString(text, "*", "");
	printf("%s\n", text);

	return 0;
}
