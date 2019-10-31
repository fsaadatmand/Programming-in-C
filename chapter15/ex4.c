/* 
 * 4. Write a program that merges lines alternately from two files and writes
 * the results to stdout. If one file has fewer lines than the other, the
 * remaining lines from the larger file should simply be copied to stdout.
 *
 * By Faisal Saadatmand
 */

#include <stdio.h>
#include <stdlib.h>

#define NAME_MAXLEN 64
#define MAXLEN 1000

int main(void) 
{
	char name1[NAME_MAXLEN], name2[NAME_MAXLEN];
	char line[MAXLEN];
	FILE *file1, *file2;
	
	printf("Merge lines from two files alternately.\n");

	printf("Enter name of file 1: ");
	scanf("%63s", name1);

	printf("Enter name of file 2: ");
	scanf("%63s", name2);

	if (!(file1 = fopen(name1, "r"))) {
		fprintf(stderr, "Can't open %s for reading.\n", name1);
		exit (EXIT_FAILURE);
	}

	if (!(file2 = fopen(name2, "r"))) {
		fprintf(stderr, "Can't open %s for reading.\n", name2);
		exit (EXIT_FAILURE);
	}

	/* Read line per line using fgets() and print to stdout using printf() */
	while (!feof(file1) || !feof(file2)) {
		if (fgets(line, MAXLEN, file1))
			printf("%s", line);             
		if (fgets(line, MAXLEN, file2))
			printf("%s", line);
	}

	fclose(file1);
	fclose(file2);

	exit (EXIT_SUCCESS);
}
