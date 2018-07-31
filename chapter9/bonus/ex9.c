/* 
 * Function to replace string s1 inside source with character string s2. (Ver. 2) 
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

/* Function to remove a specified number of charachters from */
void removeString(char source[], int index, int nChar)
{	
	int i;

	i = index + nChar;
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

bool replaceString(char source[], const char s1[], const char s2[])
{
	int findString(char source[], const char search[]);
	void removeString(char source[], int index, int nChar);
	void insertString(char source[], const char inStr[], int position);

	int  i = 0, position;
	bool succeeded = false;

	while (s1[i] != '\0')
		++i;

	position = findString(source, s1);
	if (position == -1)           /* match not found; terminate function */
		return succeeded;
	else {
		removeString(source, position, i);
		insertString(source, s2, position);
		succeeded = true;
	}
	return succeeded;
}

int main(void) 
{
	bool replaceString(char source[], const char s1[], const char s2[]);

	bool stillFound;
	char text[40] = "0123456789 ten eleven   .";

	do
		stillFound = replaceString(text," ", "");
	while (stillFound);           /* remove all blank spaces */

	printf("%s\n", text);

	return 0;
}
