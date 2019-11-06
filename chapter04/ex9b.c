/* 
 * 9. Rewrite Programs 4.2 through 4.5, replacing all uses of the for statement
 * with equivalent while statements. Run each program to verify that both
 * versions are identical.
 *
 * By Faisal Saadatmand
 */

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
