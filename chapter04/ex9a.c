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
	int n, triangularNumber;

	triangularNumber = 0;

	n = 1;
	while (n <= 200) {	
		triangularNumber = triangularNumber + n;
		++n;
	}
	printf("The 200th tiangular number is %i\n", triangularNumber);

	return 0;
}
