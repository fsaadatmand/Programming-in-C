/*
 * 9. Rewrite the readLine() function from Chapter 9 so that it uses a
 * character pointer rather than an array.
 *
 * By Faisal Saadatmand
 */

#include <stdio.h>

#define SIZE 1000

void readLine(char *);

/* Function to read a line of text from the terminal */
void readLine(char *buffer)
{
	char ch;
			
	do {
		ch = getchar();
		*buffer++  = ch;
	} while (ch != '\n');

	*buffer = '\0';
}

int main(void)
{
	char line[SIZE];

	printf("Enter a line of text (max %i characters):\n", SIZE);
	readLine(line);
	printf("%s", line);
	return 0;
}
