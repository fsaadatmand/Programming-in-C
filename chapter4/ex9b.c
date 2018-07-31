/* 
 * Program (4.3) to generate a table of triangular numbersi.
 * Replace for with while loop 
 * */

#include <stdio.h>

int main(void)
{
	int n = 1, triangularNumber;

	printf("TABLE OF TRIANGULAR NUMBERS\n\n");
	printf(" n        Sum from 1 to n\n");
	printf("---       ---------------\n");

	triangularNumber = 0;

	while (n <= 10) {
		triangularNumber += n;
		printf(" %2i         %i\n", n, triangularNumber);
		++n;
	}

	return 0;
}

