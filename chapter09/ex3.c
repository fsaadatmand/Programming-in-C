/* 
 * 3. The countWords() function from Programs 9.7 and 9.8 incorrectly counts a
 * word that contains an apostrophe as two separate words.  Modify this
 * function to correctly handle this situation. Also, extend the function to
 * count a sequence of positive or negative numbers, including any embedded
 * commas and periods, as a single word.
 * By Faisal Saadatmand
 */

#include <stdio.h>
#include <stdbool.h>

/* functions */
bool alphaNumeric(const char);
int countWords(const char []);

/* alphaNumeric: returns true if c is an alphanumeric character,
 * otherwise, return false */
bool alphaNumeric(const char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') 
			|| (c >= '0' && c <= '9'))
		return true;
	return false;
}

/* specialChar: returns true if c is a special character as defined in the
 * function, otherwise return false */
bool specialChar(const char c)
{
	if (c == '\'' || c == '-' || c == '+' || c == ',' || c  == '.')
		return true;
	return false;
}

/* Function to count the number of words in a string */
int countWords(const char string[])
{
	int  i, wordCount = 0;
	bool lookingForWord = true;

	for (i = 0; string[i] != '\0'; ++i) {
		if (specialChar(string[i]))
			continue; // skip special charachters
		if (alphaNumeric(string[i])) {
			if (lookingForWord) {
				++wordCount;
				lookingForWord = false;
			}
		} else
			lookingForWord = true;
	}
	return wordCount;
}

int main(void) 
{
	const char text1[] = "Well, here goes.";
	const char text2[] = "And here we go...again.";
	const char text3[] = "We've done it.";
	const char text4[] = "let's try some numbers 123,45 55 9.4.";
	const char text5[] = "-123,45 55 +9.4";

	printf("%s -> %i\n", text1, countWords(text1));
	printf("%s -> %i\n", text2, countWords(text2));
	printf("%s -> %i\n", text3, countWords(text3));
	printf("%s -> %i\n", text4, countWords(text4));
	printf("%s -> %i\n", text5, countWords(text5));

	return 0;
}
