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
	int n, number, triangularNumber, counter;

	counter = n = 1;
	while (counter <= 5) {
		printf("What is the value of triangular number %i? ", counter);
		scanf("%i", &number);

		triangularNumber = 0;

		while (n <= number) {
			triangularNumber += n;
			++n;
		}

		printf("Triangular number %i is %i\n\n", number, triangularNumber);
		++counter;
	}
	return 0;
}
