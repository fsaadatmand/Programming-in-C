/* 
 * Program to print m to n columns of each line in a file.
 * By Faisal Saadatmand 
 */

#include <stdio.h>
#include <string.h>

int main(void) 
{
	char fileName[64], line[81];
	char *lnPtr;
	int m, n; 
	FILE *inFile;

	/* Ask user of file name */
	printf("Enter name of file to be used: ");
	scanf("%63s", fileName);

	/* Open file */
	if ((inFile = fopen(fileName, "r")) == NULL) {
		printf("Can't open %s for reading.\n", fileName);
		return 1;
	}
	
	/* Ask user for the values of m and n */
	printf("Enter a value of m: ");
	scanf("%i", &m);

	printf("Enter the value of n: ");
	scanf("%i", &n);
	
	while (fgets(line, 80, inFile) != NULL) {
			lnPtr = line;       /* set pointer to the beginning of the line */
			lnPtr += m - 1;     /* Increment pointer's position by m columns */
			printf("%.*s\n", n - (m - 1), lnPtr);
		}	

	/* Close open files */
		fclose(inFile);
		
	return 0;
}
