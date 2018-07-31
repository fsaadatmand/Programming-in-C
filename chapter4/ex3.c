/* 
 * A program to generate every fifth triangular number for n, where n range is between 5 and 50.
 * by Faisal Saadatmand
*/
 
#include <stdio.h>

int main(void)
{
	int n, tri_nu;

	for (n = 5; n <= 50 ; n = n + 5) {
		tri_nu = n * ( n + 1 ) / 2;
		printf("The %2ith triangular number is %i\n", n, tri_nu);
	}

	return 0;
}
	
