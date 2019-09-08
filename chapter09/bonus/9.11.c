/* Function to convert a string to an integer using isdigit and atoi routines */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int main(void) 
{
	int  i = 0;
	char string[30];
	bool invalidChar = false;

	printf("Enter a string to convert into an interger number: ");
	scanf("%s", &string);

	if (string[i] == '-')
		++i;

	for (; string[i] != '\0'; ++i)
		if (isdigit(string[i]) == false) {
			invalidChar = true;
			break;
		}	

	if (invalidChar)
		printf("The string contains an invalid digit character.\n\n");
	else
		printf("%i\n", atoi(string));

	return 0;
}
