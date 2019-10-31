/* 
 * 3. Write a program to copy one file to another, replacing all lowercase
 * characters with their uppercase equivalents.
 * By Faisal Saadatmand
 */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define NAME_MAXLEN 64

int main(void) 
{
	char inName[NAME_MAXLEN], outName[NAME_MAXLEN];
	int  c;
	FILE *in, *out;

	/* Get file name from user */
	printf("Enter name of the file to be copied: ");
	scanf("%64s", inName);

	printf("Enter name of the output file: ");
	scanf("%64s", outName);

	/* Open input file */
	if (!(in = fopen(inName, "r"))) {
		fprintf(stderr, "Can't open %s for reading.\n", inName);
		exit(EXIT_FAILURE);
	}

	/* Open output file */
	if (!(out = fopen(outName, "w"))) {
		fprintf(stderr, "Can't open %s for writing.\n", outName);
		exit(EXIT_FAILURE);
	}

	/* Copy in to out */
	while ((c = getc(in)) != EOF)
		putc(toupper(c), out);

	/* Close open files */
	fclose(in);
	fclose(out);

	exit (EXIT_SUCCESS);
}
