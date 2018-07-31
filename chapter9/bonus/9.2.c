/* count the number of characters in a string using strlen function */

#include <stdio.h>
#include <string.h>

int main(void)
{

	const char word1[] = { 'a','s','t','e','r','\0' };
	const char word2[] = { 'a', 't', '\0' };
	const char word3[] = { 'a', 'w', 'e', '\0' };

	printf("%i	%i	%i\n", strlen(word1),
			strlen(word2), strlen(word3));

	return 0;
}
