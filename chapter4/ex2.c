/*
 * A programme to display a table of n and n^2, where n is 1 to 10.
 * by Faisal Saadatmand
 */

#include <stdio.h>

int main(void)
{
	int n, nxn;
	
		printf("Table of n and n x n,  where n is 1 to 10\n\n");
		printf("n\tn x n\n");
		printf("---\t--------\n");		

		for (n = 1; n <= 10; ++n) {
			nxn = n * n;
			printf("%2i\t%3i\n", n, nxn);
		}

	return 0;
}
