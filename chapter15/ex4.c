/* 
 * 4. Write a program that merges lines alternately from two files and writes
 * the results to stdout. If one file has fewer lines than the other, the
 * remaining lines from the larger file should simply be copied to stdout.
 * By Faisal Saadatmand
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
	char name1[64], name2[64];
	FILE *file1, *file2;
	char line[81];
	
	printf("Merge lines from two files alternately.\n");

	/* Get the names from user */
	printf("Enter name of file 1: ");
	scanf("%63s", name1);

	printf("Enter name of file 2: ");
	scanf("%63s", name2);

	/* Open files */
	if ((file1 = fopen(name1, "r")) == NULL) {
		printf("Can't open %s for reading.\n", name1);
		exit (EXIT_FAILURE);
	}

	if ((file2 = fopen(name2, "r")) == NULL) {
		printf("Can't open %s for reading.\n", name2);
		exit (EXIT_FAILURE);
	}

	/* Read line per line using fgets() and print to stdout using printf() */
	while (!feof(file1) || !feof(file2)) {  /* Test for end-of-file condition */
		if (fgets(line, 80, file1) != NULL) /* extract and print lines */
			printf("%s", line);             
		if (fgets(line, 80, file2) != NULL)
			printf("%s", line);
	}

	/* Close open files */
	fclose(file1);
	fclose(file2);

	exit (EXIT_SUCCESS);
}
