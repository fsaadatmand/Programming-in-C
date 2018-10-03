/* 
 * 8. Program 4.5 allows the user to type in only five different numbers.
 * Modify that program so that the user can type in the number of triangular
 * numbers to be calculated.
 * By Faisal Saadatmand
 */

#include <stdio.h>

int main(void)
{
	int n, number, triangularNumber, nTriangular,  counter;
	
	printf("How many triangular numbers to calculate? ");
	scanf("%i", &nTriangular);

	for (counter = 1; counter <= nTriangular; ++counter) {

		printf("What triangular number do you want? ");
		scanf("%i", &number);

		triangularNumber = 0;
		
		for (n = 1; n <= number; ++n)
			triangularNumber += n;

		printf("Triangular number %i is %i\n\n", number, triangularNumber);
	}
	return 0;
}

