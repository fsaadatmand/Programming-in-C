/* 
 * 5. Write a program that writes columns m through n of each line of a file to
 * stdout. Have the program accept the values of m and n from the terminal
 * window.
 *
 * By Faisal Saadatmand 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN 1000
#define NAME_MAXLEN 64
#define isInBounds(N) (N) > 0 && (N) < MAXLEN

int main(void) 
{
	char fileName[NAME_MAXLEN], line[MAXLEN], *line_begin;
	int m, n, length; 
	FILE *inFile;

	printf("Enter name of file to be used: ");
	scanf("%63s", fileName);

	if (!(inFile = fopen(fileName, "r"))) {
		fprintf(stderr, "Can't open %s for reading.\n", fileName);
		exit(EXIT_FAILURE);
	}

	printf("For every line, print columns m through n: (1-999)\n");
	printf("m: ");
	if (!scanf("%i", &m)) {
		fclose(inFile);
		exit(EXIT_FAILURE);
	}

	printf("n: ");
	if (!scanf("%i", &n)) {
		fclose(inFile);
		exit(EXIT_FAILURE);
	}

	line_begin = &line[m - 1];
	length = n - m + 1;

	/* boundary check */
	if (!(isInBounds(length) && isInBounds(m) && isInBounds(n))) {
		fprintf(stderr, "ERROR: invalid range\n");
		fclose(inFile);
		exit(EXIT_FAILURE);
	}

	printf("\n");
	while (fgets(line, MAXLEN, inFile))
		fprintf(stdout, "%.*s\n", length, line_begin);

	fclose(inFile);

	exit(EXIT_SUCCESS);
}
