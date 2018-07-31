/* 
 * Counting words. This version handle words with apostraphe
 * and counts positive or negative sequences of numbers
 * as words, with or without embeded commas or periods.
 * */

#include <stdio.h>
#include <stdbool.h>

/* Function to determine if a character is alphabetic */
bool alphabetic(const char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return true;
	else
		return false;
}

/* function to determine if a character is a number */
bool numeric(const char c)
{
	if (c >= '0' && c <='9')
		return true;
	else
		return false;
}

/* Function to count the number of words in a string */
int countWords(const char string[])
{
	bool alphabetic(const char c), numeric(const char c); 

	int  i, wordCount = 0;
	bool lookingForWord = true, isLetter = false, isNumber = false; 

	for (i = 0; string[i] != '\0'; ++i) 
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
		/* words with an postraphe */
		} else if (string[i] == '\'' && isLetter)
			lookingForWord = false;
		/* number with an embeded comma or period */
		else if ((string[i] == 44 || string[i] == 46) && isNumber)
			lookingForWord = false;
		else
			lookingForWord = true;

	return wordCount;
}

int main(void) 
{
	const char text1[] = "Well, here goes.";
	const char text2[] = "And here we go...again.";
	const char text3[] = "We've done it.";
	const char text4[] = "let's try some numbers 123,45 55 9.4.";

	int   countWords(const char string[]);

	printf("%s - words = %i\n", text1, countWords(text1));
	printf("%s - words = %i\n", text2, countWords(text2));
	printf("%s - words = %i\n", text3, countWords(text3));
	printf("%s - words = %i\n", text4, countWords(text4));

	return 0;
}
