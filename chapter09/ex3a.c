/* 
 * 3. The countWords() function from Programs 9.7 and 9.8 incorrectly counts a
 * word that contains an apostrophe as two separate words.  Modify this
 * function to correctly handle this situation. Also, extend the function to
 * count a sequence of positive or negative numbers, including any embedded
 * commas and periods, as a single word. (alternate version)
 * By Faisal Saadatmand
 */

#include <stdio.h>
#include <stdbool.h>

bool alphabetic(const char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return true;
	else
		return false;
}

/* Function to determine if a character is a number */
bool numeric(const char c)
{
	if (c >= '0' && c <= '9')
		return true;
	else
		return false;
}

void readLine(char buffer[])
{
	char character;
	int  i = 0;

	do {
		character = getchar();
		buffer[i] = character;
		++i;
	} while (character != '\n');

	buffer[i - 1] = '\0';
}

int countWords(const char string[])
{
	bool alphabetic(const char c), numeric(const char c);

	int  i,wordCount = 0;
	bool lookingForWord = true, isLetter = true, isNumber = false;

	for (i = 0; string[i]; ++i)
		if (alphabetic(string[i])) {
			if (lookingForWord) {
				++wordCount;
				lookingForWord = false;
				isLetter = true;
			}
		} else if (numeric(string[i])) {
			if (lookingForWord) {
				++wordCount;
				lookingForWord = false;
				isNumber = true;
			}
		/* words with apostrophe */
		} else if (string[i] == '\'' && isLetter)
			lookingForWord = false;
		/* numbers with an embeded comma or peroid */
		else if (string[i] == 44 || string[i] == 46 && isNumber)
			lookingForWord = false;
		else
			lookingForWord = true;

	return wordCount;
}

int main (void) 
{
	char  text[81];
	int   totalWords = 0;
	int   countWords(const char string[]);
	void  readLine(char buffer[]);
	bool  endOfText = false;

	printf("Type in your text.\n");
	printf("When you are done, press 'RETURN'.\n\n");

	while (! endOfText) {
		readLine(text);
		if (text[0] == '\0')
			endOfText = true;
		else
			totalWords += countWords(text);
	}
	printf("\nThere are %i words in the above text.\n", totalWords);

	return 0;
}
