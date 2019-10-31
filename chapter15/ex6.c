/* 
 * 6. Write a program that displays the contents of a file at the terminal 20
 * lines at a time. At the end of each 20 lines, have the program wait for a
 * character to be entered from the terminal. If the character is the letter q,
 * the program should stop the display of the file; any other character should
 * cause the next 20 lines from the file to be displayed.
 *
 * By Faisal Saadatmand
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 1000
#define MAXLINES 20
#define NAME_MAXLEN 64

int main(void) 
{
	int  i;
	char fileName[NAME_MAXLEN], line[MAXLEN];
	FILE *inFile;

	printf("Enter the name of file to read: ");
	scanf("%63s", fileName);

	if (!(inFile = fopen(fileName, "r"))) {
		fprintf(stderr, "Can't open %s for reading.\n", fileName);
		exit(EXIT_FAILURE);
	}

	while (getchar() != 'q') 
		for (i = 0; i < MAXLINES; ++i)
			fprintf(stdout, " %s\n", fgets(line, MAXLEN, inFile));

	fclose(inFile);

	exit(EXIT_SUCCESS);
}
