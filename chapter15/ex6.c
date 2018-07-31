/* 
 * Program that prints 20 lines of text from a file, waits for input and 
 * pints the next 20 lines. Program exits if the character q is inputed.
 * By Faisal Saadatmand
 */

#include <stdio.h>

int main(void) 
{
	int  i;
	char fileName[64], line[81], input;
	FILE *inFile;

	printf("Enter the name of file to read: ");
	scanf("%63s", fileName);

	if ((inFile = fopen(fileName, "r")) == NULL) {
		printf("Can't open %s for reading.\n", fileName);
		return 1;
	}

	while (input != 'q') {
		for (i = 1; i <= 20; ++i)
			fprintf(stdout, fgets(line, 80, inFile));
		scanf("%c", &input);
	}

	return 0;
}
