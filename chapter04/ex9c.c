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
	int n = 1, number, triangularNumber;

	printf("Waht triangular number do you want? ");
	scanf("%i", &number);

	triangularNumber = 0;

	while (n <= number) {
		triangularNumber += n;
		++n;
	}

	printf("Triangular number %i is %i\n", number, triangularNumber);
	
	return 0;
}
