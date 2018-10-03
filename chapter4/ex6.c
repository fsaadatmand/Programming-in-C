/* 
 * 6. A minus sign placed in front of a field width specification causes the
 * field to be displayed left-justified. Substitute the following printf()
 * statement for the corresponding statement in Program 4.2, run the program,
 * and compare the outputs produced by both programs.
 *    printf ("%-2i           %i\n", n, triangularNumber);
 * By Faisal Saadatmand
 */

#include <stdio.h>

int main(void)
{
	int n, triangularNumber;

	triangularNumber = 0;
	for (n = 1; n <= 200; n = n + 1)
		triangularNumber = triangularNumber + n;
	/* Substituted the original printf statement for the following statement */
	printf("%-2i                    %i\n", n, triangularNumber);

	return 0;
}
